#include "managementUnit.h"
#include<vector>
#include <string>
#include <iostream>
#include <fstream>
#include "renter.h"
#include "carData.h"
#include "transferUnit.h"
using namespace std;

void managementUnit::addRenter(string fileName, string ID, string name, string age, string gender, string Lno)
{
	vector<renter> exportedRenterData = TransferUnit.exportDriverData(fileName);
	exportedRenterData.push_back(renter(ID, name, age, gender, Lno));
	TransferUnit.importDriverData(exportedRenterData, fileName);
}

void managementUnit::removeRenter(string fileName, string ID)
{
	vector<renter> exportedRenterData = TransferUnit.exportDriverData(fileName);
	for(int i = 0; i < exportedRenterData.size(); i++)
	{
		if (exportedRenterData[i].getID() == ID)
		{
			exportedRenterData.erase(exportedRenterData.begin() + i);
		}
	}
	TransferUnit.importDriverData(exportedRenterData, fileName);
}

void managementUnit::addCar(string fileName, string plateNo, string owner, string renter)
{
	vector<carData> exportedCarData = TransferUnit.exportCarData(fileName);
	exportedCarData.push_back(carData(plateNo, owner, renter));
	TransferUnit.importCarData(exportedCarData, fileName);
}

void managementUnit::removeCar(string fileName, string plateNo)
{
	vector<carData> exportedCarData = TransferUnit.exportCarData(fileName);
	for (int i = 0; i < exportedCarData.size(); i++)
	{
		if (exportedCarData[i].getPlateNumber() == plateNo)
		{
			exportedCarData.erase(exportedCarData.begin() + i);
		}
	}
	TransferUnit.importCarData(exportedCarData, fileName);
}
