/*Saya Muhamad Furqon Al-Haqqi NIM 2207207 mengerjakan LP4 dalam mata kuliah DPBO
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "Vehicle.cpp"
#include "Car.cpp" 
#include "Motorcycle.cpp" 
#include "Garage.cpp" 
#include "ParkingLot.cpp" 
#include "Table.cpp"

int main(){

    vector<Car> cars; //list of car
    Car car1("A123B","Ford",2022,"Merah",6,4);  //3 objek awal car
    Car car2("B345C","Volvo",2021,"Hijau",6,4);
    Car car3("C678D","BMW",2020,"Kuning",6,4);

    cars.push_back(car1); //masukin 3 objek awal ke list
    cars.push_back(car2);
    cars.push_back(car3);

    vector<Motorcycle> motors; //list of motorcycle
    Motorcycle motor1("Z987Y","Yamaha",2010,"Hitam",4,"Matic"); //3 objek awal motor
    Motorcycle motor2("X654W","Honda",2009,"Putih",3,"Bebek");
    Motorcycle motor3("V321U","Suzuki",2008,"Hitam",4,"Bebek");
    motors.push_back(motor1); //masukin 3 objek awal ke list
    motors.push_back(motor2);
    motors.push_back(motor3);

    vector<Vehicle*> vehicles; //list of vehicle
    vehicles.push_back(&car1); //masukin 3 objek awal car & 3 objek awal motorcycle ke list vehicle
    vehicles.push_back(&car2);
    vehicles.push_back(&car3);
    vehicles.push_back(&motor1);
    vehicles.push_back(&motor2);
    vehicles.push_back(&motor3);

    vector<Garage> garages; //list of garage
    Garage garage1("Garasi Lorem","20m2",vehicles); //2 objek awal car
    Garage garage2("Garasi Ipsum","10m2",vehicles);
    garages.push_back(garage1); //masukin 2 objek awal ke list
    garages.push_back(garage2);

    vector<ParkingLot> parkingLots; //list of parkingLot
    ParkingLot parkLot1 = ParkingLot(200,4,vehicles); //2 objek awal car
    ParkingLot parkLot2 = ParkingLot(100,4,vehicles);
    parkingLots.push_back(parkLot1); //masukin 2 objek awal ke list
    parkingLots.push_back(parkLot2);

    Table tableVehicle("Table Vehicle"); //objek table buat vehicle
    int nColVehicle = 4;
    string colNameVehicle[] = {"platNomor","merk","tahunProduksi","warna"};
    tableVehicle.printTableVehicle(nColVehicle,colNameVehicle,vehicles);

    Table tableCar("Table Car"); //objek table buat car
    int nColCar = 6;
    string colNameCar[] = {"platNomor","merk","tahunProduksi","warna","jmlKursi","jmlPintu"};
    tableCar.printTableCar(nColCar,colNameCar,cars);

    Table tableMotorcycle("Table Motorcycle"); //objek table buat motorcycle
    int nColMotorcycle = 6;
    string colNameMotorcycle[] = {"platNomor","merk","tahunProduksi","warna","kapasitasTangki","jenisMotor"};
    tableMotorcycle.printTableMotorcycle(nColMotorcycle,colNameMotorcycle,motors);
    
    Table tableGarage("Table Garage"); //objek table buat garage
    int nColGarage = 3;
    string colNameGarage[] = {"namaGarasi","luasGarasi","daftarKendaraan"};
    tableGarage.printTableGarage(nColGarage,colNameGarage,garages);
    
    Table tableParkingLot("Table ParkingLot"); //objek table buat parkingLot
    int nColParkingLot = 3;
    string colNameParkingLot[] = {"kapasitas","jmlKendaraanNow","daftarKendaraan"};
    tableParkingLot.printTableParkingLot(nColParkingLot,colNameParkingLot,parkingLots);

    return 0;
}