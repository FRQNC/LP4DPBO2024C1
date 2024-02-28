from Car import Car
from Motorcycle import Motorcycle

class Garage:

    __namaGarasi = ""
    __luasGarasi = ""
    __daftarKendaraan = list()

    def __init__(self, namaGarasi="", luasGarasi="", daftarKendaraan=list()):
        self.__namaGarasi = namaGarasi
        self.__luasGarasi = luasGarasi
        self.__daftarKendaraan = daftarKendaraan
    
    def setNamaGarasi(self, namaGarasi):
        self.__namaGarasi = namaGarasi

    def setLuasGarasi(self, luasGarasi):
        self.__luasGarasi = luasGarasi

    def setDaftarKendaraan(self, daftarKendaraan):
        self.__daftarKendaraan = daftarKendaraan
    
    def getNamaGarasi(self):
        return self.__namaGarasi

    def getLuasGarasi(self):
        return self.__luasGarasi

    def getDaftarKendaraan(self):
        return self.__daftarKendaraan
    
    def getByColName(self, colName=""):
        if colName == "namaGarasi":
            return self.getNamaGarasi()
        elif colName == "luasGarasi":
            return self.getLuasGarasi()
        elif colName == "daftarKendaraan":
            return self.getDaftarKendaraan()

    def addKendaraan(self, vehicle):
        exist = False
        for i in self.__daftarKendaraan:
            if i.getPlatNomor() == vehicle.getPlatNomor():
                exist = True
        if(not exist):
           self.__daftarKendaraan.append(vehicle)
        else:
            print("Kendaraan dengan plat nomor " + vehicle.getPlatNomor() + " sudah ada!")

    def removeKendaraan(self, platNomor):
        for i in self.__daftarKendaraan:
            if i.__getPlatNomor() == platNomor:
                self.__daftarKendaraan.remove(i)