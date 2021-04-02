#include "financeData.h"
#include "visitor.h"

ostream& operator<<(ostream& out, const financeData& FD)
{
    out << "Finance data (state): " << FD.name
        << "\nYear: " << FD.year
        << "\nRetirement revenue: " << FD.retirement
        << "\nTotal government expenditures: " << FD.expenditures
        << "\nTaxes: " << FD.taxes
        << "\nUnemployment revenue: " << FD.unemployment
        << "\nEducation spending: " << FD.education
        << "\nHospital spending: " << FD.hospitals;
    return out;    
}

void financeData::accept(class Visitor& v) { v.visit(this); }
