#pragma once
#include<vector>
#include <string>
#include <iostream>
#include <fstream>
#include "renter.h"
#include "carData.h"
#include "transferUnit.h"
using namespace std;
class DataDisplayUnit
{
	transferUnit TransferUnit;

public:
	vector<carData> returnAvailableCars(string);
	vector<carData> returnRentedCars(string);

};

