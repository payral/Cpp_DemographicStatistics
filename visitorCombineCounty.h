#ifndef VCOMBOC_H
#define VCOMBOC_H

#include "hospitalData.h"
#include "cityHospitalData.h"
#include "demogData.h"
#include "countyDemogData.h"
#include "visitor.h"
#include "parse.h"
#include <memory>
#include <fstream>
#include <string>
#include <vector>

class visitorCombineCounty : public Visitor {
//TODO fill in
public:
    visitorCombineCounty(string filename) {
        std::ifstream myFile(filename);

    // Make sure the file is open
    if(!myFile.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    if(myFile.good()) {
        consumeColumnNames(myFile);

        // Helper vars
        std::string line, state, junk;

        // Now read data, line by line and enter into the map
        while(std::getline(myFile, line)) {

          std::stringstream ss(line);

          string city = getFieldNQ(ss);
          state = getFieldNQ(ss);
          junk = getFieldNQ(ss);
          string county = getFieldNQ(ss);

          string cityKey = city+state;

          cityToCounty[cityKey] = county;

          //cout << "line: " << line << endl;
          //cout << "pair (city, county): " << city << ", " << county << " state " << junk << endl;
        }
        // Close file
        myFile.close();
        }
    }


       void visit(const hospitalData* h){
            int cityError = 0;
            int loggedCity = 0;
            int numCountyH = 0;
           cityHospitalData* hInfo=(cityHospitalData*)h;
           if(hInfo) { 
            string city = hInfo->getCity();
            //city names can be redundent
            string cityKey = city+hInfo->getState();
            string county = "";
            string countyKey= "";
            //figure out the county
            if (cityToCounty.count(cityKey) >= 1) {
              county = cityToCounty[cityKey];
            } else {
                county = "unknown " + hInfo->getState();
                cityError++;
            }
            countyKey = county+hInfo->getState();
            //if first county entry, create it
            if (allCountyHData.count(countyKey) < 1) {
                //cout << "Making a new county entry (hospital): " << countyKey << endl;
                //make the new data
                //cout<<countyKey;
                c.push_back(countyKey);
                allCountyHData[countyKey] = new comboHospitalData(county +" County", hInfo->getState());
                numCountyH++;
            } 
            //either way now add this city hospital to the right county
            comboHospitalData* chInfo = allCountyHData[countyKey];
            if(chInfo) { 
                chInfo->addHospitaltoRegion(hInfo);
                loggedCity++;
            } else {
                cout << "Error should not happen - allCounty data map fail" << endl;
            }
        } else {
            cout << "Error should not happen - hospital dynamic cast fail" << endl;
        }  
       }


       void visit(const demogData* d){
           countyDemogData* cInfo= (countyDemogData*)d;
            string a=cInfo->getCounty();
            size_t found=a.find(" County");
            if(found!=string::npos)
                a.erase(found,7);
            string countyKey=a+cInfo->getState();

            //cout<<countyKey;
            b.push_back(countyKey);
            if (allCountyDData.count(countyKey) < 1) {
            allCountyDData[countyKey] = (comboDemogData*)d;
        }    
            //if(countyKey=="Weston CountyWY")
            //cout<<*(allCountyDData[countyKey]);
            //cout<<allCountyDData.size()<<endl;
        }
        void compare(){
            int sum=0;
            for(int j=0;j<allCountyDData.size();j++){
                for(int i=0;i<allCountyHData.size();i++){
                    size_t found = c[i].find(b[j]);
                        if(found != string::npos) {
                        sum++;
                    }
                }
             }
             cout<<sum;
        }


        void visit(financeData* f) { return; }


       std::map<string, comboDemogData*> countyDmap() {return allCountyDData;}
       void countyDmapsize() {cout<< allCountyDData.size()<<endl;}
       comboDemogData* countyDmapEntry(string countyN) {return allCountyDData[countyN];}
       
       std::map<string, comboHospitalData*> countyHmap() {return allCountyHData;}
       void countyHmapsize() {cout<< allCountyHData.size()<<endl;}
       comboHospitalData* countyHmapEntry(string countyN) {return allCountyHData[countyN];}
       

    private:
        //map for county hospital data
        std::map<string, comboHospitalData*> allCountyHData;
        //map for county name to demog data
        std::map<string, comboDemogData*> allCountyDData;
        //helper map to create aggregates from city -> county
        std::map<string, string> cityToCounty;
        vector<string> c;
        vector<string> b;        
};

#endif
