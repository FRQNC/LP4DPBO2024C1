#pragma once

#include <iostream>
#include <string>

using namespace std;

class Vehicle{
    private:
        string platNomor;
        string merk;
        int tahunProduksi;
        string warna;
    public:

        Vehicle(){

        }

        Vehicle(string platNomor){
            this->platNomor = platNomor;
            this->merk = "";
            this->tahunProduksi = -1;
            this->warna = "";
        }
        Vehicle(string platNomor, string merk){
            this->platNomor = platNomor;
            this->merk = merk;
            this->tahunProduksi = -1;
            this->warna = "";
        }
        Vehicle(string platNomor, string merk, int tahunProduksi){
            this->platNomor = platNomor;
            this->merk = merk;
            this->tahunProduksi = tahunProduksi;
            this->warna = "";
        }
        Vehicle(string platNomor, string merk, int tahunProduksi, string warna){
            this->platNomor = platNomor;
            this->merk = merk;
            this->tahunProduksi = tahunProduksi;
            this->warna = warna;
        }

        void setPlatNomor(string platNomor) { this->platNomor = platNomor; }
        void setMerk(string merk) { this->merk = merk; }
        void setWarna(string warna) { this->warna = warna; }
        void setTahunProduksi(int tahunProduksi) { this->tahunProduksi = tahunProduksi; }
        
        string getPlatNomor() { return platNomor; }
        string getMerk() { return merk; }
        string getWarna() { return warna; }
        int getTahunProduksi() { return tahunProduksi; }

        string getByColName(string colName){
            if(colName == "platNomor"){ return this->getPlatNomor(); }
            else if(colName == "merk"){ return this->getMerk(); }
            else if(colName == "warna"){ return this->getWarna(); }
            else if(colName == "tahunProduksi"){ return to_string(this->getTahunProduksi()); }
        }

        ~Vehicle(){

        }
};