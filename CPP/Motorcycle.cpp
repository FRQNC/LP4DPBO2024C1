#pragma once
#include <iostream>
#include <string>
#include "Vehicle.cpp"

using namespace std;

class Motorcycle : public Vehicle{
    private:
        int kapasitasTangki;
        string jenisMotor;
    public:
        Motorcycle(){

        }
        Motorcycle(string platNomor, string merk, int tahunProduksi, string warna, int kapasitasTangki) : Vehicle(platNomor, merk, tahunProduksi, warna){
            this->kapasitasTangki = kapasitasTangki;
            this->jenisMotor = "";
        }
        Motorcycle(string platNomor, string merk, int tahunProduksi, string warna, int kapasitasTangki, string jenisMotor) : Vehicle(platNomor, merk, tahunProduksi, warna){
            this->kapasitasTangki = kapasitasTangki;
            this->jenisMotor = jenisMotor;
        }

        void setKapasitasTangki(int kapasitasTangki){
            this->kapasitasTangki = kapasitasTangki;
        }
        void setJenisMotor(string jenisMotor){
            this->jenisMotor = jenisMotor;
        }

        int getKapasitasTangki(){
            return this->kapasitasTangki;
        }
        string getJenisMotor(){
            return this->jenisMotor;
        }

        string getByColName(string colName){
            if(colName == "platNomor"){
                return this->getPlatNomor();
            }
            else if(colName == "merk"){
                return this->getMerk();
            }
            else if(colName == "warna"){
                return this->getWarna();
            }
            else if(colName == "tahunProduksi"){
                return to_string(this->getTahunProduksi());
            }
            else if(colName == "jenisMotor"){
                return this->getJenisMotor();
            }
            else if(colName == "kapasitasTangki"){
                return to_string(this->getKapasitasTangki());
            }
        }

        ~Motorcycle(){

        }
};