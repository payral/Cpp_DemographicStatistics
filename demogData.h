#ifndef DEMOGD_H
#define DEMOGD_H

#include <iostream>
#include "placeData.h"

using namespace std;

/* class to represent generic demographic data all regional level */
class demogData: public placeData
{
    public:
        demogData(const string inS, double in65, double in18, double in5,
            double inBA, double inHS, double inPov, int inPop) :
            placeData(inS, 8), over65(in65), under18(in18), under5(in5),
            BAup(inBA), HSup(inHS), belowPov(inPov), pop2014(inPop) {}

        demogData(const string inS) :
            placeData(inS, 8), over65(0), under18(0), under5(0), BAup(0),
            HSup(0), belowPov(0), pop2014(0) {}

        string getState() const { return name; }

        /* these return percentages */
        double getpopOver65() const
        { return 100.0f * (double)over65 / pop2014; }
        double getpopUnder18() const
        { return 100.0f * (double)under18 / pop2014; }
        double getpopUnder5() const
        { return 100.0f * (double)under5 / pop2014; }
        double getBAup() const
        { return 100.0f * (double)BAup / pop2014; }
        double getHSup() const
        { return 100.0f * (double)HSup / pop2014; }
        double getBelowPoverty() const
        { return 100.0f * (double)belowPov / pop2014; }

        // these are counts
        double getpopOver65Count() const { return (double)over65; }
        double getpopUnder18Count() const { return (double)under18; }
        double getpopUnder5Count() const { return (double)under5; }
        double getBAupCount() const { return (double)BAup; }
        double getHSupCount() const { return (double)HSup; }
        double getBelowPovertyCount() const { return (double)belowPov; }

        int getPop() const { return pop2014; }

        friend ostream& operator<<(ostream& out, const demogData& DD);

        void accept(class Visitor& v);

    protected:
        /* store counts */
        int over65, under18, under5, BAup, HSup, belowPov, pop2014;
};

#endif
