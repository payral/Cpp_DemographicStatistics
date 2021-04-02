#include "comboHospitalData.h"

// add in another hospital data
void comboHospitalData::addHospitaltoRegion(const hospitalData* HD)
{
	overall += HD -> getOverall();
	mortality += HD -> getMortality();
	readmission += HD -> getReadmit();
	numHospitals++;
}
