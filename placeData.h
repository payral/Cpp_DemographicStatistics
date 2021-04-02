#ifndef PLACE_H
#define PLACE_H

#include <string>

using namespace std;

/* very general data type for any kind of place data */
class placeData
{
    public:
        placeData(const string inN, const int numF) : 
            name(inN), numFields(numF) {}

        const string getName() const { return name; }
        
        //virtual void toString(ostream& os) const = 0;
    
        virtual void accept(class Visitor &v) = 0;
        //std::vector<shared_ptr<placeData>> getData() {return pileOfData;}

    protected:
  	    const string name;
        const int numFields;
        //std::vector<shared_ptr<placeData>> pileOfData;
};

#endif
