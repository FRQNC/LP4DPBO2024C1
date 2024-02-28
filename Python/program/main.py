# Saya Muhamad Furqon Al-Haqqi NIM 2207207 mengerjakan LP4 dalam mata kuliah DPBO 
# untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
from Car import Car
from Motorcycle import Motorcycle
from Garage import Garage
from ParkingLot import ParkingLot
from Table import Table

cars = list()
car1 = Car("A123B","Ford",2022,"Merah",6,4)
car2 = Car("B345C","Volvo",2021,"Hijau",6,4)
car3 = Car("C678D","BMW",2020,"Kuning",6,4)
cars.append(car1)
cars.append(car2)
cars.append(car3)

tableCars = Table("Table Car")
carsColN = 6
carsColName = ["platNomor","merk","tahunProduksi","warna","jmlKursi","jmlPintu"]
tableCars.printTable(carsColN,carsColName,cars)

motors = list()
motor1 = Motorcycle("Z987Y","Yamaha",2010,"Hitam","Matic","4L")
motor2 = Motorcycle("X654W","Honda",2009,"Putih","Bebek","3L")
motor3 = Motorcycle("V321U","Suzuki",2008,"Hitam","Bebek","4L")
motors.append(motor1)
motors.append(motor2)
motors.append(motor3)

motorsColN = 6
motorsColName = ["platNomor","merk","tahunProduksi","warna","jenisMotor","kapasitasTangki"]
tableMotors = Table("Table Motor")
tableMotors.printTable(motorsColN,motorsColName,motors)

garages = list()
garage1 = Garage("Garasi Lorem","20m2",cars)
garage2 = Garage("Garasi Ipsum","10m2",motors)
garages.append(garage1)
garages.append(garage2)

tableGarage = Table("Table Garasi")
garageColN = 3
garageColName = ["namaGarasi","luasGarasi","daftarKendaraan"]
tableGarage.printTableWithList(garageColN,garageColName,garages)

parkingLots = list()
parkLot1 = ParkingLot(200,0,motors)
parkLot2 = ParkingLot(200,0,cars)
parkingLots.append(parkLot1)
parkingLots.append(parkLot2)

tableParkLot = Table("Table Parking Lot")
parkLotColN = 3
parkLotColName = ["kapasitas","jmlKendaraanNow","daftarKendaraan"]
parkLot1.addKendaraan(car1)
tableParkLot.printTableWithList(parkLotColN,parkLotColName,parkingLots)