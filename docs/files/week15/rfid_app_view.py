import sys
from PyQt5.QtWidgets import QApplication, QWidget, QLabel
from PyQt5.QtGui import QPixmap
from python_serial_01 import read_rfid, try_serial
import threading
import time


class MainWindow():
    height = 400
    width = height * 1.618

    def __init__(self):
        self.app = QApplication(sys.argv)
        self.widget = QWidget()
        self.text1 = "Fab Academy 2021, week15"
        self.text2 = "0"*45
        self.setLabel()
        self.setTitle()
        self.setLogo()
        self.setConnection_icon()
        # self.setRFID_img()
        self.setMilk_img()

    def setLabel(self):
        self.label = QLabel(self.widget)
        self.label.setText(self.text2)
        self.label.resize(500, 50)
        self.label.move(200, 50)

    def setTitle(self):
        self.widget.setGeometry(50,50,self.width,self.height)
        self.widget.setWindowTitle(self.text1)

    def setConnection_icon(self):
        self.con_icon_holder = QLabel(self.widget)
        if try_serial():
            self.con_icon = QPixmap('ok.png')
        else:
            self.con_icon = QPixmap('not.png')
        self.con_icon_holder.setPixmap(self.con_icon)
        self.con_icon_holder.resize(self.con_icon.width(), self.con_icon.height())
        self.con_icon_holder.move(self.width -50, self.height-50 )

    def setRFID_img(self):
        self.rfid_icon_holder = QLabel(self.widget)
        self.rfid_icon = QPixmap('tag.png')
        self.rfid_icon_holder.setPixmap(self.rfid_icon)
        self.rfid_icon_holder.resize(self.rfid_icon.width(), self.rfid_icon.height())
        self.rfid_icon_holder.move(50, self.height -100)

    def setMilk_img(self):
        self.milk_icon_holder = QLabel(self.widget)
        self.milk_icon = QPixmap('milk.png')
        self.milk_icon_holder.setPixmap(self.milk_icon)
        self.milk_icon_holder.resize(self.milk_icon.width(), self.milk_icon.height())
        self.milk_icon_holder.move(50, (self.height-self.milk_icon.height())*0.5)

    def setLogo(self):
        self.logo = QPixmap('cow.png')
        self.logo_holder = QLabel(self.widget)
        self.logo_holder.setPixmap(self.logo)
        self.logo_holder.resize(self.logo.width(), self.logo.height())
        self.logo_holder.move(50, 50)


    def display(self):
        self.widget.show()
        sys.exit(self.app.exec_())


a = MainWindow()


def update_label():
    while True:
        print("loop1")
        time.sleep(0.5)
        data = read_rfid()
        a.label.setText(data)


updater = threading.Thread(target=update_label)
updater.start()
a.display()
