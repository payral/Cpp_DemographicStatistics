#ifndef COMBOD_H
#define COMBOD_H

#include "demogData.h"

/* aggregated demographic data for a given regional level
 * (state - or larger region) */
class comboDemogData : public demogData 
{
    public:
        comboDemogData(const string inR, const string inS) :
            demogData(inS), numCombined(0), region(inR) {}

        int getNumCombined() const { return numCombined; } 
        const string getRegionType() const { return region; } 

        void addDemogtoRegion(const demogData* DD);

        friend ostream& operator<<(ostream& out, const comboDemogData& DI)
        {
            out << "Combined data at level: " << DI.region
                << " includes num subregions: " << DI.numCombined << endl
                << (demogData)DI; // call on parent output
            return out;
        }

    private:
        int numCombined;
        const string region; // either state or could be larger region
};

#endif
