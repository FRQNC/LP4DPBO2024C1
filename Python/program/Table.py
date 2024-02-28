class Table:

    __namaTable = ""
    def __init__(self, namaTable):
        self.__namaTable = namaTable

    def setNamaTable(self, namaTable):
        self.__namaTable = namaTable

    def getNamaTable(self):
        return self.__namaTable

    def findMaxLen(self, nCol, colNames, objList): #buat nyari max len tiap kolom
        maxCol = []
        for i in range(0,nCol):
            maxCol.append(len(str(colNames[i])))
        
        for obj in objList:
            for i in range(0,nCol):
                maxCol[i] = max(maxCol[i],len(str(obj.getByColName(colNames[i]))))


        total = 0 
        for i in range(0,nCol):
            total += maxCol[i]
        maxCol.append(total)
        return maxCol #return array max len yg berisi max len tiap col

    def printSpace(self, len): #print space sebanyak len
        print(" " * len,end="")

    def printTable(self, nCol, colNames, objList):
        maxLens = self.findMaxLen(nCol, colNames,objList) #cari max len tiap col
        maxTableLen = maxLens[nCol] + 2 * nCol + nCol + 1 #2*9 -> per kolom butuh minimal spasi 2, + 10 jumlah |

        print(self.getNamaTable())
        print("-"*maxTableLen)
        for i in range(0,nCol):
            print("| " + colNames[i], end="")
            self.printSpace(maxLens[i] - len(str(colNames[i])) + 1)
        print("|")
        print("-"*maxTableLen)
        
        for obj in objList:
            for i in range(0,nCol):
                objAttrib = obj.getByColName(colNames[i])
                print("| " + str(objAttrib),end="")
                self.printSpace(maxLens[i] - len(str(objAttrib)) + 1)
            print("|")
            print("-"*maxTableLen)

    def findMaxLenWithList(self, nCol, colNames, objList): #buat nyari max len tiap kolom
        maxCol = []
        for i in range(0,nCol):
            maxCol.append(len(str(colNames[i])))
        
        for obj in objList:
            for i in range(0,nCol):
                objAttrib = obj.getByColName(colNames[i])
                if type(objAttrib) == list:
                    for o in objAttrib:
                        maxCol[i] = max(maxCol[i],(len(str(o.getByColName("platNomor"))) + len(str(o.getByColName("merk"))) + 1))
                else:
                    maxCol[i] = max(maxCol[i],len(str(obj.getByColName(colNames[i]))))
        
        total = 0 
        for i in range(0,nCol):
            total += maxCol[i]
        maxCol.append(total)
        return maxCol #return array max len yg berisi max len tiap col
    
    def printTableWithList(self, nCol, colNames, objList):
        maxLens = self.findMaxLenWithList(nCol,colNames,objList) #cari max len tiap col
        maxTableLen = maxLens[nCol] + 2 * nCol + nCol + 1 #2*9 -> per kolom butuh minimal spasi 2, + 10 jumlah |

        print(self.getNamaTable())
        print("-"*maxTableLen)
        for i in range(0,nCol):
            print("| " + colNames[i], end="")
            self.printSpace(maxLens[i] - len(str(colNames[i])) + 1)
        print("|")
        print("-"*maxTableLen)
        
        for obj in objList:
            for i in range(0,nCol):
                objAttrib = obj.getByColName(colNames[i])
                if type(objAttrib) is list:
                    for o in objAttrib:
                        print("| " + o.getByColName("merk") + " " + o.getByColName("platNomor"),end="")
                        self.printSpace(maxLens[i] - len(str(o.getByColName("platNomor"))) - len(str(o.getByColName("merk"))))
                        print("|",end="")
                        if o != objAttrib[len(objAttrib) - 1]:
                            for j in range(i+1,nCol):
                                self.printSpace(maxLens[j]+2)
                                print("|",end="")
                            print()
                            print("| ",end="")
                            for k in range(0,i):
                                self.printSpace(maxLens[k]+1)
                                if(k < i-1):
                                    print("|",end="")
                                else:
                                    print(" ",end="")
                        else:
                            print()
                else:
                    print("| " + str(objAttrib),end="")
                    self.printSpace(maxLens[i] - len(str(objAttrib)) + 1)
            print("-"*maxTableLen)