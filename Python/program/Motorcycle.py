from Vehicle import Vehicle

class Motorcycle(Vehicle):

    __jenisMotor = ""
    __kapasitasTangki = ""

    def __init__(self, platNomor="", merk="", tahunProduksi=-1, warna="", jenisMotor="", kapasitasTangki=""):
        super().__init__(platNomor, merk, tahunProduksi, warna)
        self.__jenisMotor = jenisMotor
        self.__kapasitasTangki = kapasitasTangki
    
    def getJenisMotor(self):
        return self.__jenisMotor

    def setJenisMotor(self, jenisMotor):
        self.__jenisMotor = jenisMotor

    def getKapasitasTangki(self):
        return self.__kapasitasTangki

    def setKapasitasTangki(self, kapasitasTangki):
        self.__kapasitasTangki = kapasitasTangki
    
    def getByColName(self, colName=""):
        if colName == "platNomor":
            return self.getPlatNomor()
        elif colName == "merk":
            return self.getMerk()
        elif colName == "tahunProduksi":
            return self.getTahunProduksi()
        elif colName == "warna":
            return self.getWarna()
        elif colName == "jenisMotor":
            return self.getJenisMotor()
        elif colName == "kapasitasTangki":
            return self.getKapasitasTangki()