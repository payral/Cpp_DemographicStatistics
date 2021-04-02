#ifndef CITYHOSP_H
#define CITYHOSP_H

#include "hospitalData.h"

using namespace std;

/* city hospital data for specifics of CORGIS data */
class cityHospitalData : public hospitalData
{
    public:
        cityHospitalData(string inH, string inC, string inS, string inT,
            int inO, rating inM, rating inR) :
            hospitalData(inS, inO, inM, inR), city(inC), type(inT),
            hospital(inH) {}

        const string getCity() const { return city; }
        const string getType() const { return type; }
        const string getHospName() const { return hospital; }

        friend ostream& operator<<(ostream& out,
            const cityHospitalData& CHD)
        {
            out << "City: " << CHD.city << " Type: " << CHD.type
                << " name: " << CHD.hospital
                << (hospitalData)CHD;
            return out;
        }

    private:
        const string city, type, hospital;
};

#endif
