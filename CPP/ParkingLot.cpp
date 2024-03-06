#pragma once
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "Vehicle.cpp"

using namespace std;

class ParkingLot{
    private:
        int kapasitas, jmlKendaraanNow;
        vector<Vehicle*> daftarKendaraan;
    public:
        ParkingLot(){

        }
        ParkingLot(int kapasitas){
            this->kapasitas = kapasitas;
            this->jmlKendaraanNow;
            this->daftarKendaraan;
        }
        ParkingLot(int kapasitas, int jmlKendaraanNow){
            this->kapasitas = kapasitas;
            this->jmlKendaraanNow = jmlKendaraanNow;
            this->daftarKendaraan;
        }
        ParkingLot(int kapasitas, int jmlKendaraanNow, vector<Vehicle*> daftarKendaraan){
            this->kapasitas = kapasitas;
            this->jmlKendaraanNow = jmlKendaraanNow;
            this->daftarKendaraan = daftarKendaraan;
        }

        void setKapasitas(int kapasitas){
            this->kapasitas = kapasitas;
        }
        void setJmlKendaraanNow(int jmlKendaraanNow){
            this->jmlKendaraanNow = jmlKendaraanNow;
        }
        void setDaftarKendaraan(vector<Vehicle*> daftarKendaraan){
            this->daftarKendaraan = daftarKendaraan;
        }

        int getKapasitas(){
            return this->kapasitas;
        }
        int getJmlKendaraanNow(){
            return this->jmlKendaraanNow;
        }
        vector<Vehicle*> getDaftarKendaraan(){
            return this->daftarKendaraan;
        }

        string getByColName(string colName){
            if(colName == "kapasitas"){
                return to_string(this->getKapasitas());
            }
            else if(colName == "jmlKendaraanNow"){
                return to_string(this->getJmlKendaraanNow());
            }
            else if(colName == "daftarKendaraan"){
                return "list";
            }
        }
        vector<Vehicle*> getByColNameList(string colName){
            if(colName == "daftarKendaraan"){
                return this->getDaftarKendaraan();
            }
        }

        void addKendaraan(Vehicle v1){
            bool exist = false;
            for(vector<Vehicle*>::iterator it = this->daftarKendaraan.begin();it != this->daftarKendaraan.end();it++){
                if(v1.getPlatNomor() == (*it)->getPlatNomor()){
                    exist = true;
                }
            }
            if(!exist){
                this->daftarKendaraan.push_back(&v1);
            }
            else{
                cout << "Kendaraan dengan plat nomor : " << v1.getPlatNomor() << " sudah ada\n";
            }
        }

        void removeKendaraan(string platNomor){
            vector<Vehicle*>::iterator deleted = this->daftarKendaraan.begin();
            bool exist = false;
            for(vector<Vehicle*>::iterator it = this->daftarKendaraan.begin();it != this->daftarKendaraan.end();it++){
                if(platNomor == (*it)->getPlatNomor()){
                    deleted = it;
                    exist = true;
                }
            }
            if(!exist){
                cout << "Kendaraan dengan plat nomor : " << platNomor << " tidak ada!\n";
            }
            else{
                this->daftarKendaraan.erase(deleted);
            }
        }
};