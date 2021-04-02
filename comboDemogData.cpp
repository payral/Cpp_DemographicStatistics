#include "comboDemogData.h"
//#include <assert.h>

// adds the current county info to the running total
void comboDemogData::addDemogtoRegion(const demogData* DD)
{
    //assert(state.compare(CI->getState()) == 0);
    over65 += DD -> getpopOver65Count();
    under18 += DD -> getpopUnder18Count();
    under5 += DD -> getpopUnder5Count();
    BAup += DD -> getBAupCount();
    HSup += DD -> getHSupCount() ;
    belowPov += DD -> getBelowPovertyCount();
    pop2014 += DD -> getPop();
    numCombined++;
}
