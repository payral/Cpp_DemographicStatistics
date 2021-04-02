#include "demogData.h"
#include "visitor.h"

/* print county demographic data */
ostream& operator<<(ostream& out, const demogData& DD)
{
    out << "Demographics Info (State): " << DD.name
        << "\nPopulation info: \n(\% over 65): " << DD.getpopOver65()
        <<  " Count: " << DD.over65
        << "\n(\% under 18): " << DD.getpopUnder18()
        <<  " Count: " << DD.under18
        << "\n(\% under 5): " << DD.getpopUnder5()
        <<  " Count: " << DD.under5
        << "\nEducation info: \n(\% Bachelor degree or more): "
        << DD.getBAup() <<  " Count: " << DD.BAup
        << "\n(\% high school or more): " << DD.getHSup()
        <<  " Count: " << DD.HSup
        << "\n\% below poverty: " << DD.getBelowPoverty()
        <<  " Count: " << DD.belowPov
        << "\nTotal population: " << DD.pop2014;
    return out;
}

void demogData::accept(class Visitor& v) { v.visit(this); }
