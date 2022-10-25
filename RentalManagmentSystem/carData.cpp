#include "carData.h"

carData::carData(string lno, string ow, string ren)
{
	licencePlateNumber = lno;
	owner = ow;
	renter = ren;
}

string carData::getPlateNumber()
{
	return licencePlateNumber;
}

void carData::setPlateNumber(string lno)
{
	licencePlateNumber = lno;

}

string carData::getOwner()
{
	return owner;
}

void carData::setOwner(string ow)
{
	owner = ow;
}

string carData::getRenter()
{
	return renter;
}

void carData::setRenter(string ren)
{
	renter = ren;
}
