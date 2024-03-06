#pragma once
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "Vehicle.cpp"

using namespace std;

class Garage{
    private:
        string namaGarasi, luasGarasi;
        vector<Vehicle*> daftarKendaraan;
    public:
        Garage(){

        }
        Garage(string namaGarasi){
            this->namaGarasi = namaGarasi;
            this->luasGarasi = "";
            this->daftarKendaraan;
        }
        Garage(string namaGarasi, string luasGarasi){
            this->namaGarasi = namaGarasi;
            this->luasGarasi = luasGarasi;
            this->daftarKendaraan;
        }
        Garage(string namaGarasi, string luasGarasi, vector<Vehicle*> daftarKendaraan){
            this->namaGarasi = namaGarasi;
            this->luasGarasi = luasGarasi;
            this->daftarKendaraan = daftarKendaraan;
        }

        void setNamaGarasi(string namaGarasi){
            this->namaGarasi = namaGarasi;
        }
        void setLuasGarasi(string luasGarasi){
            this->luasGarasi = luasGarasi;
        }
        void setDaftarKendaraan(vector<Vehicle*> daftarKendaraan){
            this->daftarKendaraan = daftarKendaraan;
        }

        string getNamaGarasi(){
            return this->namaGarasi;
        }
        string getLuasGarasi(){
            return this->luasGarasi;
        }
        vector<Vehicle*> getDaftarKendaraan(){
            return this->daftarKendaraan;
        }

        string getByColName(string colName){
            if(colName == "namaGarasi"){
                return this->getNamaGarasi();
            }
            else if(colName == "luasGarasi"){
                return this->getLuasGarasi();
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