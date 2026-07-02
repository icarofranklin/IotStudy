import serial
import time
from datetime import datetime

PORTA = '/dev/ttyUSB0'
BAUD_RATE = 115200

try:
    print(f"Tentando conectar em {PORTA} a {BAUD_RATE} bps (Padrão 8N1)...")
    
    # Conexão com os parâmetros 8N1 explícitos
    conexao = serial.Serial(
        port=PORTA,
        baudrate=BAUD_RATE,
        bytesize=serial.EIGHTBITS,   # 8 bits de dados
        parity=serial.PARITY_NONE,   # Sem paridade (None)
        stopbits=serial.STOPBITS_ONE,# 1 bit de parada
        timeout=1
    )
    
    print("Conexão estabelecida! Pressione Ctrl+C para parar.\n")

    while True:
        agora = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        mensagem = f"{agora}\r\n"
        conexao.write(mensagem.encode('utf-8'))
        print(f"Enviado: {agora}")
        time.sleep(1)

except serial.SerialException as e:
    print(f"\n[ERRO] Problema na porta serial: {e}")
except KeyboardInterrupt:
    print("\n[INFO] Script interrompido pelo usuário.")
finally:
    if 'conexao' in locals() and conexao.is_open:
        conexao.close()
        print("Porta serial fechada com segurança.")