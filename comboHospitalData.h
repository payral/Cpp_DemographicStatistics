#ifndef COMBOH_H
#define COMBOH_H

#include "hospitalData.h"

/* aggregated hospital data for a given regional level (county or state) */
class comboHospitalData : public hospitalData
{
    public:
        comboHospitalData(const string inR, const string inS) :
            hospitalData(inS), region(inR), numHospitals(0) {}

        const string getRegion() const { return region; }
        double getNumH() const { return (double)numHospitals; }

        //note this stores a running total        
        void addHospitaltoRegion(const hospitalData* HD);

        friend ostream& operator<<(ostream& out,
            const comboHospitalData& CHD)
        {
            out << "Combined hospital data at level: " << CHD.region
                << "\nincludes num hospitals: " << CHD.numHospitals << endl
                << (hospitalData)CHD;
            return out;
        }

    private:
        string region; //either state or county
        int numHospitals;
};

#endif
