#ifndef FINANCE_H
#define FINANCE_H

#include <iostream>
#include "placeData.h"

using namespace std;

class financeData : public placeData
{
    public:
        financeData(string inS, int inY, int inR, int inEx, int inT,
            int inU, int inEd, int inH) :
            placeData(inS, 8), year(inY), retirement(inR),
            expenditures(inEx), taxes(inT), unemployment(inU),
            education(inEd), hospitals(inH) {}

        int getYear() const { return year; }
        double getRetirement() const { return (double)retirement; }
        double getExpenditures() const { return (double)expenditures; }
        double getTaxes() const { return (double)taxes; }
        double getUnemployment() const { return (double)unemployment; }
        double getEducation() const { return (double)education; }
        double getHospitals() const { return (double)hospitals; }

        friend ostream& operator<<(ostream& out, const financeData& FD);
        
        void accept(class Visitor &v);

    private:
        string state;
        int year, retirement, expenditures, taxes, unemployment,
            education, hospitals;
};

#endif
