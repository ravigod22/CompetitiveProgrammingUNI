import time
from datetime import datetime
import sys

# Lista de sitios de redes sociales que quieres bloquear
sitios_bloqueados = [
    "www.facebook.com", "facebook.com",
    "www.instagram.com", "instagram.com",
    "www.twitter.com", "twitter.com",
    "web.whatsapp.com", "manhwas.net"
]

# Dirección de localhost para redirigir
redirect = "127.0.0.1"

# Ruta del archivo hosts (en Windows y Unix/Linux/macOS es diferente)
hosts_path = "/etc/hosts" if sys.platform != "win32" else r"C:\Windows\System32\drivers\etc\hosts"

# Función para bloquear sitios
def bloquear_sitios():
    with open(hosts_path, "r+") as archivo:
        contenido = archivo.read()
        for sitio in sitios_bloqueados:
            if sitio not in contenido:
                archivo.write(f"{redirect} {sitio}\n")

# Función para desbloquear sitios
def desbloquear_sitios():
    with open(hosts_path, "r+") as archivo:
        contenido = archivo.readlines()
        archivo.seek(0)
        for linea in contenido:
            if not any(sitio in linea for sitio in sitios_bloqueados):
                archivo.write(linea)
        archivo.truncate()

try:
    print("Bloqueando redes sociales...")
    bloquear_sitios()
    tiempo_bloqueo = 3600  # Duración del bloqueo en segundos
    print(f"Redes sociales bloqueadas por {tiempo_bloqueo} segundos")
    time.sleep(tiempo_bloqueo)  # Cambia este valor para ajustar la duración del bloqueo
finally:
    print("Desbloqueando redes sociales...")
    desbloquear_sitios()
    print("Redes sociales desbloqueadas.")

