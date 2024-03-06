#pragma once
#include <iostream>
#include <string>
#include "Vehicle.cpp"

using namespace std;

class Car : public Vehicle{
    private:
        int jmlKursi, jmlPintu;
    public:
        Car(){

        }
        Car(string platNomor, string merk, int tahunProduksi, string warna, int jmlKursi) : Vehicle(platNomor, merk, tahunProduksi, warna){
            this->jmlKursi = jmlKursi;
            this->jmlPintu = -1;
        }
        Car(string platNomor, string merk, int tahunProduksi, string warna, int jmlKursi, int jmlPintu) : Vehicle(platNomor, merk, tahunProduksi, warna){
            this->jmlKursi = jmlKursi;
            this->jmlPintu = jmlPintu;
        }

        void setJmlKursi(int jmlKursi){
            this->jmlKursi = jmlKursi;
        }
        void setJmlPintu(int jmlPintu){
            this->jmlPintu = jmlPintu;
        }

        int getJmlKursi(){
            return this->jmlKursi;
        }
        int getJmlPintu(){
            return this->jmlPintu ;
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
            else if(colName == "jmlKursi"){
                return to_string(this->getJmlKursi());
            }
            else if(colName == "jmlPintu"){
                return to_string(this->getJmlPintu());
            }
        }

        ~Car(){
            
        }
};