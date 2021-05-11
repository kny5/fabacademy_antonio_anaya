import sys
from PyQt5.QtWidgets import QApplication, QWidget, QLabel
from python_serial_01 import read_rfid, output
import threading
import time


class MainWindow():
    def __init__(self):
        self.app = QApplication(sys.argv)
        self.widget = QWidget()
        self.text1 = "Fab Academy 2021, week15"
        self.text2 = "0"
        self.setLabel()
        self.setTitle()

    def setLabel(self):
        self.label = QLabel(self.widget)
        self.label.setText(self.text2)
        self.label.move(110, 85)

    def setTitle(self):
        self.widget.setGeometry(50,50,320,200)
        self.widget.setWindowTitle(self.text1)

    def display(self):
        self.widget.show()
        sys.exit(self.app.exec_())


a = MainWindow()


def update_label(text):
    while True:
        print("loop1")
        time.sleep(0.5)
        a.label.setText(text)


serial = threading.Thread(target=read_rfid)
updater = threading.Thread(target=update_label, args=(output,))
serial.start()
updater.start()
a.display()
