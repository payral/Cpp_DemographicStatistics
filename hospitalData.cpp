#include "hospitalData.h"
#include "visitor.h"

/* print hospital data */
ostream& operator<<(ostream& out, const hospitalData& HD)
{
    out << "Hosptial Info: " << HD.name
        << "\nOverall rating (out of 5): " << HD.overall
        << "\nmortality rating: " << HD.mortality
        << "\nreadmission rating:" << HD.readmission;
    return out;
}

void hospitalData::accept(class Visitor& v) { v.visit(this); }
