#pragma once
#include<vector>
#include <string>
#include <iostream>
#include <fstream>
#include "renter.h"
#include "carData.h"
using namespace std;
class transferUnit
{
	vector<renter> DriverData;
	vector<carData> carDataList;
public:
	void importDriverData(vector<renter>, string);
	vector<renter> exportDriverData(string);

	vector<renter> getDriverData();
	void setDriverData(vector<renter>);

	void importCarData(vector<carData>, string);
	vector<carData> exportCarData(string);

	vector<carData> getCarData();
	void seCarData(vector<carData>);

	 
};

