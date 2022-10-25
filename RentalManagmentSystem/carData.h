#pragma once
#include<vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class carData
{
	string licencePlateNumber;
	string owner;
	string renter;
public:
	carData(string, string, string);

	string getPlateNumber();
	void setPlateNumber(string);

	string getOwner();
	void setOwner(string);

	string getRenter();
	void setRenter(string);

};

