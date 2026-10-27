#include <iostream>
#include <vector>
#include <fcntl.h> // Controle de arquivos
#include <termios.h> // Configuração de terminais
#include <unistd.h> // Funções de sistema
#include <cstdint>

// Função simples para calcular o Checksum OSDP (Soma de todos os bytes em módulo 256 e invertido)
uint8_t calcularChecksum(const std::vector<uint8_t>& pacote){
    int soma =0;
    for (uint8_t byte : pacote) {
        soma += byte;
    }
    return static_cast<uint8_t>((0x100 - (soma & 0xFF)) & 0xFF);
}

int main(){
    // 1. Abrir a porta serial (Ponte física RS-485)
    const char* portaSerial = "/dev/ttyUSB0";
    int fd = open(portaSerial, O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd == -1){
        std::cerr << "Erro ao abrir a porta " << portaSerial << ". Verifique as permissões." << std::endl;
        return 1;
    }

    // 2. Configurar a porta Serial (Baud rate padrão do OSDP: 9600)
    struct termios opcoes;
    tcgetattr(fd, &opcoes);
    cfsetispeed(&opcoes, B9600);
    cfsetospeed(&opcoes, B9600);

    opcoes.c_cflag |= (CLOCAL | CREAD); // Habilita o receptor
    opcoes.c_cflag &= ~PARENB;          // Sem paridade
    opcoes.c_cflag &= ~CSTOP;           // 1 Stop bit
    opcoes.c_cflag &= ~CSIZE;          
    opcoes.c_cflag |= ~CS8;             // 8 bits de dados

    tcsetattr(fd, TCSANOW, &opcoes);

    // 3. Construir o Pacote OSDP (Comando osdp_POLL para o endereço 0)
    // O tamanho inicial é 5 bytes antes do checksum (SOM, ADDR, LEN_LSB, LEN_MSB, CTRL, CMD)
    std::vector<uint8_t> pacoteOSDP = {
        0x53, // SOM (Start of Message)
        0x00, // ADDR (Endereço do leitor: 0)
        0x06, // LEN_LSB (Tamanho total será 6 bytes: 5 do cabeçalho + 1 do checksum)
        0x00, // LEN_MSB
        0x00, // CTRL (Controle de sequência física)
        0x60  // CMD (0x60 é o código para osdp_POLL)
    };

    // Calcular o último byte (Checksum) e colocar no fim do pacote
    uint8_t csum = calcularChecksum(pacoteOSDP);
    pacoteOSDP.push_back(csum);

    // 4. Enviar os bytes pelo terminal de hardware
    std::cout << "Enviando comando osdp_POLL..." << std::endl;
    ssize_t bytesEnviados = write(fd, pacoteOSDP.data(), pacoteOSDP.size());

    if (bytesEnviados < 0){
        std::cerr << "Falha ao transmitir os dados." << std::endl;
    }else{
        std::cout << "Sucesso! " << bytesEnviados << " bytes transmitidos." << std::endl;
    }
    // 5. Fechar o descritor
    close(fd);
    return 0;
}