#ifndef VCOMBOS_H
#define VCOMBOS_H

#include "hospitalData.h"
#include "demogData.h"
#include "financeData.h"
#include "visitor.h"
#include <memory>
#include <string>

using namespace std;

class visitorCombineState : public Visitor {
//TODO fill in
public:
    void visit(const hospitalData* h) {
            string stateName = h->getState();
            if (allStateHospData.count(stateName) < 1) {
                allStateHospData[stateName] = new comboHospitalData("state", stateName);
            }
            allStateHospData[stateName]->addHospitaltoRegion(h);       
    }

    void visit(const demogData* d){
            string stateName = d->getState();
            if (allStateDemogData.count(stateName) < 1 ){
                allStateDemogData[stateName]= new comboDemogData("state",stateName);
        }
        allStateDemogData[stateName]->addDemogtoRegion(d);
        
    }

    void visit(financeData* f)
    {
        int year = f -> getYear();
        if (year == 2013)
        {
            string stateKey = abbreviate[f -> getName()];
            if (allFinanceData.count(stateKey) < 1)
            {
                allFinanceData[stateKey] = f;
            }
        }
    }

    std::map<string, comboDemogData*> stateDmap() {return allStateDemogData;}
    comboDemogData* stateDmapEntry(string stateN){return allStateDemogData[stateN];}
    std::map<string, comboHospitalData*> stateHmap() {return allStateHospData;}
    comboHospitalData* stateHmapEntry(string stateN) {return allStateHospData[stateN];}

    map<string, financeData*> stateFmap() { return allFinanceData; }
    financeData* stateFmapEntry(string stateN)
    { return allFinanceData[stateN]; }

private:
    std::map<string, comboDemogData*> allStateDemogData;
    std::map<string, comboHospitalData*> allStateHospData;
    map<string, financeData*> allFinanceData;

    map<string,string> abbreviate = {
    {"Alabama","AL"},
    {"Alaska","AK"},
    {"Arizona","AZ"},
    {"Arkansas","AR"},
    {"California","CA"},
    {"Colorado","CO"},
    {"Connecticut","CT"},
    {"Delaware","DE"},
    {"Florida","FL"},
    {"Georgia","GA"},
    {"Hawaii","HI"},
    {"Idaho","ID"},
    {"Illinois","IL"},
    {"Indiana","IN"},
    {"Iowa","IA"},
    {"Kansas","KS"},
    {"Kentucky","KY"},
    {"Louisiana","LA"},
    {"Maine","ME"},
    {"Maryland","MD"},
    {"Massachusetts","MA"},
    {"Michigan","MI"},
    {"Minnesota","MN"},
    {"Mississippi","MS"},
    {"Missouri","MO"},
    {"Montana","MT"},
    {"Nebraska","NE"},
    {"Nevada","NV"},
    {"New Hampshire","NH"},
    {"New Jersey","NJ"},
    {"New Mexico","NM"},
    {"New York","NY"},
    {"North Carolina","NC"},
    {"North Dakota","ND"},
    {"Ohio","OH"},
    {"Oklahoma","OK"},
    {"Oregon","OR"},
    {"Pennsylvania","PA"},
    {"Rhode Island","RI"},
    {"South Carolina","SC"},
    {"South Dakota","SD"},
    {"Tennessee","TN"},
    {"Texas","TX"},
    {"Utah","UT"},
    {"Vermont","VT"},
    {"Virginia","VA"},
    {"Washington","WA"},
    {"West Virginia","WV"},
    {"Wisconsin","WI"},
    {"Wyoming","WY"},
    };
};

#endif
