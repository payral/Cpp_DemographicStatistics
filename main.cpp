#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
#include <math.h>
#include "demogData.h"
#include "comboDemogData.h"
#include "comboHospitalData.h"
#include "countyDemogData.h"
#include "comboHospitalData.h"
#include "hospitalData.h"
#include "cityHospitalData.h"
#include "parse.h"
#include "visitorReport.h"
#include "visitorCombineState.h"
#include "visitorCombineCounty.h"
#include "stats.h"
#include "statTool.h"
#include "statGatherer.h"
#include "financeData.h"

using namespace std;


int main() {
/*
    std::vector<shared_ptr<placeData>> pileOfData;

    //set up outpout format
    cout << std::setprecision(2) << std::fixed;

    //read in the hospital data
    read_csv(pileOfData, "hospitals.csv", HOSPITAL);
    //read in the demographic data
    read_csv(pileOfData, "county_demographics.csv", DEMOG);

    read_csv(pileOfData, "finance.csv", FINANCE);
 
    //cout<<pileOfData.size();

    //create a visitor to combine the state data
    visitorCombineState theStates;
    //create the state demographic data
    statTool::createStateData(pileOfData, theStates);
    //theStates.printAllStates();

    int i = 0;
    for (auto entry : theStates.stateFmap())
    {
        cout << i << ": " << *entry.second;
        i++;
    }

    i = 0;
    for (auto entry : theStates.stateDmap())
    {
        cout << i << ": " << *entry.second;
        i++;
    }

    //create a visitor to combine the county data (need aux map city-> county)
    visitorCombineCounty theCounties("simple_uscities.csv");
    statTool::createCountyData(pileOfData, theCounties);
    //theCounties.countyHmapsize();
    //theCounties.countyDmapsize();
    //theCounties.compare();
    //cout<<"what"<<endl;

    //create statGathers to help make the data one for states one for counties
    stateGather fillStates;
    countyGather fillCounties;


    //Do stats work here these are examples...

    //mixed data use 'sample'
    cout << "**State data over 65  and number Hospitals: " << endl;
    statTool::computeStatsMixRegionData(&theStates, &fillStates, &demogData::getpopOver65, &comboHospitalData::getNumH);
    cout << "County data over 65 and number Hospitals: " << endl;
    statTool::computeStatsMixRegionData(&theCounties, &fillCounties, &demogData::getpopOver65, &comboHospitalData::getNumH);

    //demogxdemog sample
    cout << "State data Pop under 5 and BA up: " << endl;
    statTool::computeStatsDemogRegionData(&theStates, &fillStates, &demogData::getpopUnder5, &demogData::getBAup,
        &demogData::getpopUnder5Count, &demogData::getBAupCount);
    cout << "County data Pop under 5 and BA up: " << endl;
    statTool::computeStatsDemogRegionData(&theCounties, &fillCounties, &demogData::getpopUnder5, &demogData::getBAup,
        &demogData::getpopUnder5Count, &demogData::getBAupCount);

    cout << "State overall hospital and population over 65: " << endl;
    statTool::computeStatsMixRegionData(&theStates, &fillStates, &demogData::getpopOver65, &comboHospitalData::getOverallRate);

    cout<<"Counties number of hospitals and population with BA or higher"<<endl;
    statTool::computeStatsMixRegionData(&theCounties, &fillCounties, &demogData::getBAup, &comboHospitalData::getNumH);

    cout<<"Counties: overall hospital rating and population below poverty"<<endl;
    statTool::computeStatsMixRegionData(&theCounties, &fillCounties, &demogData::getBelowPoverty, &comboHospitalData::getOverallRate);

    cout<<"Counties: population with BA or higher and population below poverty"<<endl;
    statTool::computeStatsDemogRegionData(&theCounties, &fillCounties, &demogData::getBAup, &demogData::getBelowPoverty,
        &demogData::getBAupCount, &demogData::getBelowPovertyCount);
    
    cout<<"Counties: population with high school or higher and population below poverty"<<endl;
    statTool::computeStatsDemogRegionData(&theCounties, &fillCounties, &demogData::getHSup, &demogData::getBelowPoverty,
        &demogData::getHSupCount, &demogData::getBelowPovertyCount);

    cout<<"Counties: population younger than 18 and population younger than 5"<<endl;
    statTool::computeStatsDemogRegionData(&theCounties, &fillCounties, &demogData::getpopUnder18, &demogData::getpopUnder5,
        &demogData::getpopUnder18Count, &demogData::getpopUnder5Count);
    
    cout<<"Counties: population younger than 18 and population over 65"<<endl;
    statTool::computeStatsDemogRegionData(&theCounties, &fillCounties, &demogData::getpopUnder18, &demogData::getpopOver65,
        &demogData::getpopUnder18Count, &demogData::getpopOver65Count);
*/


    return 0;
}



