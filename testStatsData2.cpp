

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "demogData.h"
#include "comboDemogData.h"
#include "comboHospitalData.h"
#include "countyDemogData.h"
#include "comboHospitalData.h"
#include "hospitalData.h"
#include "cityHospitalData.h"
#include "financeData.h"
#include "parse.h"
#include "tddFuncs.h"
#include "visitorReport.h"
#include "visitorCombineState.h"
#include "visitorCombineCounty.h"
#include "stats.h"
#include "statTool.h"
#include "statGatherer.h"
using namespace std;

int main() {


  cout << "Testing stats on Data with Finance" << endl;

  std::vector<shared_ptr<placeData>> pileOfData;

  //read in the hospital data
  read_csv(pileOfData, "hospitals.csv", HOSPITAL);
   
  //read in the demographic data
  read_csv(pileOfData, "county_demographics.csv", DEMOG); 

  read_csv(pileOfData, "finance.csv", FINANCE);
  
  visitorCombineState theStates;
  //use visitor pattern to be able to aggregate
  statTool::createStateData(pileOfData, theStates);

  stateGather fillStates;

  vector<double> over65;
  vector<double> retirement;

  fillStates.gatherPerStats(&theStates, over65, retirement, &demogData::getpopOver65Count, &financeData::getRetirement);

  double o65 = stats::computeMean(over65); 
  double r = stats::computeMean(retirement);  
  double cc = stats::computeCorCoeffSample(over65, retirement);

  cout << "\nMean count over 65: " << o65 << endl
       << "Mean retirement spending: " << r << endl
       << "Correlation coefficient: " << cc << endl;


  vector<double> BA;
  vector<double> education;

  fillStates.gatherPerStats(&theStates, BA, education, &demogData::getBAupCount, &financeData::getEducation);

  double ba = stats::computeMean(BA); 
  double ed = stats::computeMean(education);  
  cc = stats::computeCorCoeffSample(BA, education);

  cout << "\nMean count college degrees: " << ba << endl
       << "Mean education spending: " << ed << endl
       << "Correlation coefficient: " << cc << endl;


  vector<double> numH;
  vector<double> hSpending;

  fillStates.gatherPerStats(&theStates, numH, hSpending, &comboHospitalData::getNumH, &financeData::getHospitals);

  double nh = stats::computeMean(numH); 
  double hs = stats::computeMean(hSpending);  
  cc = stats::computeCorCoeffSample(numH, hSpending);

  cout << "\nMean number of hospitals: " << nh << endl
       << "Mean hospital spending: " << hs << endl
       << "Correlation coefficient: " << cc << endl;


  return 0;
}
