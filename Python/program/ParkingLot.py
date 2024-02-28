from Car import Car
from Motorcycle import Motorcycle

class ParkingLot:
    __kapasitas = 0
    __jmlKendaraanNow = 0
    __daftarKendaraan = list()

    def __init__(self, kapasitas=0, jmlKendaraanNow=0, daftarKendaraan=list()):
        self.__kapasitas = kapasitas
        self.__jmlKendaraanNow = jmlKendaraanNow
        self.__daftarKendaraan = daftarKendaraan
        if(len(self.__daftarKendaraan) != 0 and len(self.__daftarKendaraan) > self.__jmlKendaraanNow):
            self.__jmlKendaraanNow = len(self.__daftarKendaraan)

    
    def setKapasitas(self, kapasitas):
        self.__kapasitas = kapasitas
    
    def setJmlKendaraanNow(self, jmlKendaraanNow):
        self.__jmlKendaraanNow = jmlKendaraanNow

    def setDaftarKendaraan(self, daftarKendaraan):
        self.__daftarKendaraan = daftarKendaraan
    
    def getKapasitas(self):
        return self.__kapasitas
    
    def getJmlKendaraanNow(self):
        return self.__jmlKendaraanNow
    
    def getDaftarKendaraan(self):
        return self.__daftarKendaraan
    
    def getByColName(self, colName=""):
        if colName == "kapasitas":
            return self.getKapasitas()
        elif colName == "jmlKendaraanNow":
            return self.getJmlKendaraanNow()
        elif colName == "daftarKendaraan":
            return self.getDaftarKendaraan()
    
    def addKendaraan(self, vehicle):
        exist = False
        for i in self.__daftarKendaraan:
            if i.getPlatNomor() == vehicle.getPlatNomor():
                exist = True
        if(not exist):
           self.__daftarKendaraan.append(vehicle)
           self.__jmlKendaraanNow += 1
        else:
            print("Kendaraan dengan plat nomor " + vehicle.getPlatNomor() + " sudah ada!")

    def removeKendaraan(self, platNomor):
        for i in self.__daftarKendaraan:
            if i.__getPlatNomor() == platNomor:
                self.__daftarKendaraan.remove(i)
                self.__jmlKendaraanNow -= 1
