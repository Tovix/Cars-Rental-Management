#pragma once
#include<vector>
#include <string>
#include <iostream>
#include <fstream>
#include "renter.h"
#include "carData.h"
#include "DataDisplayUnit.h"
#include "transferUnit.h"
#include "managementUnit.h"
using namespace std;

class carRentManagment
{
	transferUnit TransferUnit;
	managementUnit MU;
public:
	int DBRent(string, string, string, string);
	void nonDBRent(string, string, string, string, string, string, string, string);
	int f(int x);
	int find(float f[], int size, float target);
	int isPrime(int number);
	void storePrime();
};

