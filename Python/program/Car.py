from Vehicle import Vehicle

class Car(Vehicle):
    
    __jmlKursi = 0
    __jmlPintu = 0

    def __init__(self, platNomor="", merk="", tahunProduksi=-1, warna="", jmlKursi=0, jmlPintu=0):
        super().__init__(platNomor, merk, tahunProduksi, warna)
        self.__jmlKursi = jmlKursi
        self.__jmlPintu = jmlPintu

    def getJmlKursi(self):
        return self.__jmlKursi

    def setJmlKursi(self, jmlKursi):
        self.__jmlKursi = jmlKursi

    def getJmlPintu(self):
        return self.__jmlPintu

    def setJmlPintu(self, jmlPintu):
        self.__jmlPintu = jmlPintu

    def getByColName(self, colName=""):
        if colName == "platNomor":
            return self.getPlatNomor()
        elif colName == "merk":
            return self.getMerk()
        elif colName == "tahunProduksi":
            return self.getTahunProduksi()
        elif colName == "warna":
            return self.getWarna()
        elif colName == "jmlKursi":
            return self.getJmlKursi()
        elif colName == "jmlPintu":
            return self.getJmlPintu()