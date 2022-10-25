#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "renter.h"
#include "carData.h"
#include "DataDisplayUnit.h"
#include "transferUnit.h"
#include "carRentManagment.h"
#include "managementUnit.h"
using namespace std;

int carRentManagment::DBRent(string RentersfileName, string CarsfileName, string ID, string LNo)
{
	vector<renter> exportedRenterList = TransferUnit.exportDriverData(RentersfileName);
	vector<carData> exportedCarList = TransferUnit.exportCarData(CarsfileName);
	string renterName;
	bool nameExist = false;
	bool carExist = false;
	for(int i = 0; i < exportedRenterList.size(); i++)
	{
		if(exportedRenterList[i].getID() == ID)
		{
			renterName = exportedRenterList[i].getName();
			nameExist = true;
			
		}
	}
	for (int i = 0; i < exportedCarList.size(); i++)
	{
		if (exportedCarList[i].getPlateNumber() == LNo)
		{
			carExist = true;
			exportedCarList[i].setRenter(renterName);
		}
	}
	TransferUnit.importCarData(exportedCarList, CarsfileName);
	if(nameExist == true)
	{
		if(carExist == true)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	else if(carExist == false && nameExist == false)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

void carRentManagment::nonDBRent(string rentersFileName, string CarsFileName, string ID, string name, string age, string gender, string RLNo, string LNo)
{
	MU.addRenter(rentersFileName, ID, name, age, gender, RLNo);
	vector<carData> exportedCarList = TransferUnit.exportCarData(CarsFileName);
	for (int i = 0; i < exportedCarList.size(); i++)
	{
		if (exportedCarList[i].getPlateNumber() == LNo)
		{
				exportedCarList[i].setRenter(name);
		}
	}
	TransferUnit.importCarData(exportedCarList, CarsFileName);
	
}

int carRentManagment::f(int x)
{
	if(x < 2)
	{
		return 2;
	}
	else
	{
		return f(x - 2) * 3;
	}
}

int carRentManagment::find(float f[], int size, float target)
{
	bool flag = false;
	int i = 0;
	for(i = 0; i < size; i++)
	{
		if(f[i] == target)
		{
			flag = true;
			break;
		}
	}
	if(flag == true)
	{
		return i;
	}
	else
	{
		return -1;
	}
}

int carRentManagment::isPrime(int n)
{
	bool isPrime = true;
	if (n == 0 || n == 1) 
	{
		isPrime = false;
	}
	else {
		for (int i = 2; i <= n / 2; i ++)
		{
			if (n % i == 0)
			{
				isPrime = false;
				break;
			}
		}
	}
	if (isPrime)
		return 1;
	else
		return 0;
}

void carRentManagment::storePrime()
{
	int count = 0;
	
	for(int i = 0; i < 1000; i++)
	{
		if(isPrime(i) == 0)
		{
			cout << i << endl;
			count++;
		}
		if(count == 100)
		{
			break;
		}
	}
}


