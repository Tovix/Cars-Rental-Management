#include<vector>
#include <string>
#include <iostream>
#include <fstream>
#include "renter.h"
#include "carData.h"
#include "DataDisplayUnit.h"
using namespace std;

vector<carData> DataDisplayUnit::returnAvailableCars(string fileName)
{
    vector<carData> exportedCarList = TransferUnit.exportCarData(fileName);
    vector<carData> availableCarList;
    for(int i = 0; i < exportedCarList.size(); i++)
    {
        if(exportedCarList[i].getRenter() == "No Renter")
        {
            availableCarList.push_back(exportedCarList[i]);
        }
    }
    return availableCarList;
}

vector<carData> DataDisplayUnit::returnRentedCars(string fileName)
{
    vector<carData> exportedCarList = TransferUnit.exportCarData(fileName);
    vector<carData> rentedCarList;
    for (int i = 0; i < exportedCarList.size(); i++)
    {
        if (exportedCarList[i].getRenter() != "No Renter")
        {
            rentedCarList.push_back(exportedCarList[i]);
        }
    }
    return rentedCarList;
}
