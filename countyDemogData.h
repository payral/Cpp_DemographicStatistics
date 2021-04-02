#ifndef CDEMOG_H
#define CDEMOG_H

#include "demogData.h"

using namespace std;

/* county demographic data used to represent the CORGIS data */
class countyDemogData : public demogData
{
    public:
        countyDemogData(const string inC, const string inS, double in65,
            double in18, double in5, double inBA, double inHS,
            double inPov, int inPop) :
            demogData(inS, in65, in18, in5, inBA, inHS, inPov, inPop),
            county(inC) {}

        string getCounty() const { return county; }

        friend ostream& operator<<(ostream& out, const countyDemogData& DI)
        {
            out << "County: " << DI.county << endl
                << (demogData)DI; //call on parent output
            return out;
        }   

    private:
        const string county;
};

#endif
