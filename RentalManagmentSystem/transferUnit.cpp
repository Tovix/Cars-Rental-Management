#include "transferUnit.h"
#include<vector>
#include <string>
#include <iostream>
#include <fstream>
#include "renter.h"
using namespace std;

void transferUnit::importDriverData(vector<renter> driverData, string fileName)
{
	fstream file;
	file.open(fileName, ios::out | ios::trunc);
	for(int i = 0; i < driverData.size(); i++)
	{
		file << driverData[i].getID() << "," << driverData[i].getName() << "," << driverData[i].getAge()
			<< ","<< driverData[i].getGender()<< "," << driverData[i].getLNo() << endl;
	}
	file.close();

}

vector<renter> transferUnit::exportDriverData(string fileName)
{
	ifstream file;
	file.open(fileName);
	string name, gender, id, age, LNo;
	vector<renter> renterList;
	while(getline(file, id, ','))
	{
		getline(file, name, ',');
		getline(file, age, ',');
		getline(file, gender, ',');
		getline(file, LNo, '\n');
		renterList.push_back(renter(id, name, age, gender, LNo));
	}
	return renterList;

}

vector<renter> transferUnit::getDriverData()
{
	return DriverData;
}

void transferUnit::setDriverData(vector<renter> dd)
{
	DriverData = dd;
}

void transferUnit::importCarData(vector<carData> carDataList, string fileName)
{
	fstream file;
	file.open(fileName, ios::out | ios::trunc);
	for (int i = 0; i < carDataList.size(); i++)
	{
		file << carDataList[i].getPlateNumber() << "," << carDataList[i].getOwner() << "," << carDataList[i].getRenter() << endl;
	}
	file.close();
}

vector<carData> transferUnit::exportCarData(string fileName)
{
	ifstream file;
	file.open(fileName);
	string LNo, owner, renter;
	vector<carData> CarDataList;
	while (getline(file, LNo, ','))
	{
		getline(file, owner, ',');
		getline(file, renter, '\n');
		CarDataList.push_back(carData(LNo, owner, renter));
	}
	return CarDataList;
}

vector<carData> transferUnit::getCarData()
{
	return carDataList;
}

void transferUnit::seCarData(vector<carData> carDataLst)
{
	carDataList = carDataLst;
}
