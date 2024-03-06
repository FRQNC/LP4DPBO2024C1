#pragma once
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "Vehicle.cpp"
#include "Car.cpp"
#include "Motorcycle.cpp"
#include "Garage.cpp"
#include "ParkingLot.cpp"

using namespace std;

class Table{
    private:
        string namaTable;
    public:
        Table(){

        }
        Table(string namaTable){
            this->namaTable = namaTable;
        }
        void setNamaTable(string namaTable){
            this->namaTable = namaTable;
        }
        string getNamaTable(){
            return this->namaTable;
        }

        void findMaxLenVehicle(int nCol, string colNames[], vector<Vehicle*> vehicles, int maxCol[]){
            for(int i = 0;i < nCol;i++){
                maxCol[i] = colNames[i].length();
            }
            for(vector<Vehicle*>::iterator vit = vehicles.begin(); vit != vehicles.end();vit++){
                for(int j = 0;j < nCol;j++){
                    maxCol[j] = max(maxCol[j],(int)(*vit)->getByColName(colNames[j]).length());
                }
            }
            int total = 0;
            for(int i = 0;i < nCol;i++){
                total += maxCol[i];
            }
            maxCol[nCol] = total;
        }        
        void findMaxLenCar(int nCol, string colNames[], vector<Car> cars, int maxCol[]){
            for(int i = 0;i < nCol;i++){
                maxCol[i] = colNames[i].length();
            }
            for(vector<Car>::iterator cit = cars.begin(); cit != cars.end();cit++){
                for(int j = 0;j < nCol;j++){
                    maxCol[j] = max(maxCol[j],(int)cit->getByColName(colNames[j]).length());
                }
            }
            int total = 0;
            for(int i = 0;i < nCol;i++){
                total += maxCol[i];
            }
            maxCol[nCol] = total; 
        }        
        void findMaxLenMotorcycle(int nCol, string colNames[], vector<Motorcycle> motors, int maxCol[]){
            for(int i = 0;i < nCol;i++){
                maxCol[i] = colNames[i].length();
            }
            for(vector<Motorcycle>::iterator mit = motors.begin(); mit != motors.end();mit++){
                for(int j = 0;j < nCol;j++){
                    maxCol[j] = max(maxCol[j],(int)mit->getByColName(colNames[j]).length());
                }
            }
            int total = 0;
            for(int i = 0;i < nCol;i++){
                total += maxCol[i];
            }
            maxCol[nCol] = total; 
        }        
        void findMaxLenGarage(int nCol, string colNames[], vector<Garage> garages, int maxCol[]){
            for(int i = 0;i < nCol;i++){
                maxCol[i] = colNames[i].length();
            }
            for(vector<Garage>::iterator it = garages.begin();it != garages.end();it++){
                for(int j = 0;j < nCol;j++){
                    string objAttrib = it->getByColName(colNames[j]);
                    if(objAttrib != "list"){
                        maxCol[j] = max(maxCol[j], (int)objAttrib.length());
                    }
                    else{
                        vector<Vehicle*> vehicles = it->getByColNameList(colNames[j]);
                        for(vector<Vehicle*>::iterator vit = vehicles.begin(); vit != vehicles.end();vit++){
                            maxCol[j] = max(maxCol[j],(int)(*vit)->getByColName("merk").length() + (int)(*vit)->getByColName("platNomor").length() + 1);
                        }
                    }
                }
            }
            int total = 0;
            for(int i = 0;i < nCol;i++){
                total += maxCol[i];
            }
            maxCol[nCol] = total; 
        }
        void findMaxLenParkingLot(int nCol, string colNames[], vector<ParkingLot> parkingLot, int maxCol[]){
            for(int i = 0;i < nCol;i++){
                maxCol[i] = colNames[i].length();
            }
            for(vector<ParkingLot>::iterator it = parkingLot.begin();it != parkingLot.end();it++){
                for(int j = 0;j < nCol;j++){
                    string objAttrib = it->getByColName(colNames[j]);
                    if(objAttrib != "list"){
                        maxCol[j] = max(maxCol[j], (int)objAttrib.length());
                    }
                    else{
                        vector<Vehicle*> vehicles = it->getByColNameList(colNames[j]);
                        for(vector<Vehicle*>::iterator vit = vehicles.begin(); vit != vehicles.end();vit++){
                            maxCol[j] = max(maxCol[j],(int)(*vit)->getByColName("merk").length() + (int)(*vit)->getByColName("platNomor").length() + 1);
                        }
                    }
                }
            }
            int total = 0;
            for(int i = 0;i < nCol;i++){
                total += maxCol[i];
            }
            maxCol[nCol] = total; 
        }
        void printCharNTime(int len, char c){
            for(int i = 1;i <= len;i++){
                cout << c;
            }
        }
        void printTableVehicle(int nCol, string colNames[], vector<Vehicle*> vehicles){
            int maxCol[nCol+1];

            findMaxLenVehicle(nCol,colNames,vehicles,maxCol);
            int maxTableLen = maxCol[nCol] + 2*nCol + nCol + 1;

            cout << this->namaTable << "\n";
            printCharNTime(maxTableLen,'-');
            cout << "\n";
            for(int i = 0;i < nCol;i++){
                cout << "| " << colNames[i];
                printCharNTime(maxCol[i] - colNames[i].length() + 1,' ');
            }
            cout << "|\n";
            printCharNTime(maxTableLen,'-');
            cout << "\n";
            for(vector<Vehicle*>::iterator vit = vehicles.begin(); vit != vehicles.end();vit++){
                for(int i = 0;i < nCol;i++){
                    string objAttrib = (*vit)->getByColName(colNames[i]);
                    cout << "| " << objAttrib;
                    printCharNTime(maxCol[i] - (int)objAttrib.length() + 1,' ');
                }
                cout << "|\n";
                printCharNTime(maxTableLen,'-');
                cout << "\n";
            }
        }
        void printTableCar(int nCol, string colNames[], vector<Car> cars){
            int maxCol[nCol+1];

            findMaxLenCar(nCol,colNames,cars,maxCol);
            int maxTableLen = maxCol[nCol] + 2*nCol + nCol + 1;

            cout << this->namaTable << "\n";
            printCharNTime(maxTableLen,'-');
            cout << "\n";
            for(int i = 0;i < nCol;i++){
                cout << "| " << colNames[i];
                printCharNTime(maxCol[i] - colNames[i].length() + 1,' ');
            }
            cout << "|\n";
            printCharNTime(maxTableLen,'-');
            cout << "\n";
            for(vector<Car>::iterator cit = cars.begin(); cit != cars.end();cit++){
                for(int i = 0;i < nCol;i++){
                    string objAttrib = cit->getByColName(colNames[i]);
                    cout << "| " << objAttrib;
                    printCharNTime(maxCol[i] - (int)objAttrib.length() + 1,' ');
                }
                cout << "|\n";
                printCharNTime(maxTableLen,'-');
                cout << "\n";
            }
        }
        void printTableMotorcycle(int nCol, string colNames[], vector<Motorcycle> motors){
            int maxCol[nCol+1];

            findMaxLenMotorcycle(nCol,colNames,motors,maxCol);
            int maxTableLen = maxCol[nCol] + 2*nCol + nCol + 1;

            cout << this->namaTable << "\n";
            printCharNTime(maxTableLen,'-');
            cout << "\n";
            for(int i = 0;i < nCol;i++){
                cout << "| " << colNames[i];
                printCharNTime(maxCol[i] - colNames[i].length() + 1,' ');
            }
            cout << "|\n";
            printCharNTime(maxTableLen,'-');
            cout << "\n";
            for(vector<Motorcycle>::iterator mit = motors.begin(); mit != motors.end();mit++){
                for(int i = 0;i < nCol;i++){
                    string objAttrib = mit->getByColName(colNames[i]);
                    cout << "| " << objAttrib;
                    printCharNTime(maxCol[i] - (int)objAttrib.length() + 1,' ');
                }
                cout << "|\n";
                printCharNTime(maxTableLen,'-');
                cout << "\n";
            }
        }
        void printTableGarage(int nCol, string colNames[], vector<Garage> garages){
            int maxCol[nCol+1];

            findMaxLenGarage(nCol,colNames,garages,maxCol);
            int maxTableLen = maxCol[nCol] + 2*nCol + nCol + 1;

            cout << this->namaTable << "\n";
            printCharNTime(maxTableLen,'-');
            cout << "\n";
            for(int i = 0;i < nCol;i++){
                cout << "| " << colNames[i];
                printCharNTime(maxCol[i] - colNames[i].length() + 1,' ');
            }
            cout << "|\n";
            printCharNTime(maxTableLen,'-');
            cout << "\n";
            for(vector<Garage>::iterator git = garages.begin(); git != garages.end();git++){
                for(int i = 0;i < nCol;i++){
                    string objAttrib = git->getByColName(colNames[i]);
                    if(objAttrib != "list"){
                        cout << "| " << objAttrib;
                        printCharNTime(maxCol[i] - (int)objAttrib.length() + 1,' ');
                    }
                    else{
                        vector<Vehicle*> vehicles = git->getByColNameList(colNames[i]);
                        for(vector<Vehicle*>::iterator vit = vehicles.begin(); vit != vehicles.end();vit++){
                            cout << "| " << (*vit)->getByColName("merk") << " " << (*vit)->getByColName("platNomor");
                            printCharNTime(maxCol[i] - (int)(*vit)->getByColName("merk").length() - (int)(*vit)->getByColName("platNomor").length(),' ');
                            cout << "|";
                            if((string)(*vit)->getPlatNomor() != (string)vehicles.back()->getPlatNomor()){
                                for(int j = i+1;j < nCol;j++){
                                    printCharNTime(maxCol[j]+2,' ');
                                    cout << "|";
                                }
                                cout << "\n";
                                cout << "| ";
                                for(int k = 0;k < i;k++){
                                    printCharNTime(maxCol[k]+1,' ');
                                    if(k < i-1){
                                        cout << "| ";
                                    }
                                }
                            }
                            else{
                                cout << "\n";
                            }
                        }
                    }
                }
                printCharNTime(maxTableLen,'-');
                cout << "\n";
            }
        }
        void printTableParkingLot(int nCol, string colNames[], vector<ParkingLot> parkingLots){
            int maxCol[nCol+1];

            findMaxLenParkingLot(nCol,colNames,parkingLots,maxCol);
            int maxTableLen = maxCol[nCol] + 2*nCol + nCol + 1;

            cout << this->namaTable << "\n";
            printCharNTime(maxTableLen,'-');
            cout << "\n";
            for(int i = 0;i < nCol;i++){
                cout << "| " << colNames[i];
                printCharNTime(maxCol[i] - colNames[i].length() + 1,' ');
            }
            cout << "|\n";
            printCharNTime(maxTableLen,'-');
            cout << "\n";
            for(vector<ParkingLot>::iterator git = parkingLots.begin(); git != parkingLots.end();git++){
                for(int i = 0;i < nCol;i++){
                    string objAttrib = git->getByColName(colNames[i]);
                    if(objAttrib != "list"){
                        cout << "| " << objAttrib;
                        printCharNTime(maxCol[i] - (int)objAttrib.length() + 1,' ');
                    }
                    else{
                        vector<Vehicle*> vehicles = git->getByColNameList(colNames[i]);
                        // cout << "last item = " << vehicles.back()->getPlatNomor();
                        for(vector<Vehicle*>::iterator vit = vehicles.begin(); vit != vehicles.end();vit++){
                            cout << "| " << (*vit)->getByColName("merk") << " " << (*vit)->getByColName("platNomor");
                            printCharNTime(maxCol[i] - (int)(*vit)->getByColName("merk").length() - (int)(*vit)->getByColName("platNomor").length(),' ');
                            cout << "|";
                            if((string)(*vit)->getPlatNomor() != (string)vehicles.back()->getPlatNomor()){
                                for(int j = i+1;j < nCol;j++){
                                    printCharNTime(maxCol[j]+2,' ');
                                    cout << "|";
                                }
                                cout << "\n";
                                cout << "| ";
                                for(int k = 0;k < i;k++){
                                    printCharNTime(maxCol[k]+1,' ');
                                    if(k < i-1){
                                        cout << "| ";
                                    }
                                }
                            }
                            else{
                                cout << "\n";
                            }
                        }
                    }
                }
                printCharNTime(maxTableLen,'-');
                cout << "\n";
            }
        }
};