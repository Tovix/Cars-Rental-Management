#pragma once
#include<vector>
#include <string>
#include <iostream>
#include <fstream>
#include "renter.h"
#include "carData.h"
#include "transferUnit.h"
using namespace std;
class managementUnit
{
	transferUnit TransferUnit;
public:
	void addRenter(string,string, string, string, string, string);
	void removeRenter(string,string);

	void addCar(string,string, string, string);
	void removeCar(string,string);
};

