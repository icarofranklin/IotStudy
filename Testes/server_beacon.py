import socket

# 1. Cria o socket UDP (AF_INET indica IPv4, SOCK_DGRAM indica UDP)
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# 2. Amarra o servidor para ouvir em TODAS as interfaces locais na porta 3999
sock.bind(("0.0.0.0", 3999))

print("Servidor UDP AGSinn aguardando pacotes do Beacon na porta 3999...")

# 3. Laço infinito de escuta (igual ao loop do microcontrolador)
while True:
    # O buffer de 4096 bytes é mais que suficiente para os pacotes BLE
    data, addr = sock.recvfrom(4096)

    # Exibe no terminal quem enviou (IP da placa) e o dado bruto recebido
    print(f"Recebido de {addr}: {data.decode('utf-8', errors='ignore')}")