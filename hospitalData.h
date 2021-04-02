#ifndef HOSP_H
#define HOSP_H

#include "rating.h"
#include "placeData.h"

/* class to represent hospital data */
class hospitalData : public placeData
{
    public:
        hospitalData(const string inS, int inO, rating inM, rating inR) :
            placeData(inS, 4), overall(rating(inO)), mortality(inM),
            readmission(inR) {}

        hospitalData(const string inS) :
            placeData(inS, 4), overall(-1), mortality("Unknown"),
            readmission("Unkown") {}

        string getState() const { return name; }
        rating getOverall() const { return overall; }
        rating getMortality() const { return mortality; }
        rating getReadmit() const { return readmission; }

        double getOverallRate() const { return overall.getRatingNum(); }

        friend ostream& operator<<(ostream& out, const hospitalData& HD);

        void accept(class Visitor& v);

    protected:
        rating overall, mortality, readmission;
};

#endif
