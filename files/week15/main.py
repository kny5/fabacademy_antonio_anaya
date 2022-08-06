from rfid_app_view import MainWindow
from python_serial_01 import read_rfid
import threading


def view():
    a = MainWindow()

serial = threading.Thread(target=read_rfid)
window = threading.Thread(target=view)

serial.start()
window.start()
