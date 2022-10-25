// RentalManagmentSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "renter.h"
#include "transferUnit.h"
#include "carData.h"
#include "managementUnit.h"
#include "DataDisplayUnit.h"
#include "carRentManagment.h"
using namespace std;

int main()   
{ 
	int choice = -1;
	bool renterExportFlag = false;
	bool carExportFlag = false;
	transferUnit TU;
	managementUnit MU;
	DataDisplayUnit DU;
	carRentManagment CRM;
	//
	//
	//
	int number = 200;
	while(true)
	{
		int flag = CRM.isPrime(number);
		if (flag == 1)
		{
			cout << number << endl;
			break;
		}
		number++;
	}
	CRM.storePrime();
	//
	//
	//
	vector<renter> exportedRenterData;
	vector<carData> exportedCarData;
	string driverFileName, carFileName;
	cout << "Car Rental Management System: [CRMS_0.1]" << endl;
	cout << "#######################################################" << endl;
	while (choice != 0)
	{
		cout << "1 - Export renter/car data." << endl;
		cout << "2 - Add renter to the system." << endl;
		cout << "3 - Add car to the system." << endl;
		cout << "4 - Remove renter from the system." << endl;
		cout << "5 - Remove car from the system." << endl;
		cout << "6 - Display car(s) available for rent." << endl;
		cout << "7 - Display rented car(s)." << endl;
		cout << "8 - rent a car." << endl;
		cout << "0 - Quit." << endl;
		cout << "#######################################################" << endl;
		cout << "Enter your choice:" << endl;
		cin >> choice;
		cout << "#######################################################" << endl;
		if (choice == 1)
		{
			int innerChoice = 0;
			cout << "1 - Export renter Data." << endl;
			cout << "2 - Export car Data." << endl;
			cout << "#######################################################" << endl;
			cout << "Enter your choice:" << endl;
			cout << "#######################################################" << endl;
			cin >> innerChoice;
			if (innerChoice == 1)
			{
				
				cout << "Enter the name of the file (.csv):" << endl;
				cout << "#######################################################" << endl;
				cin >> driverFileName;
				cout << "#######################################################" << endl;
				exportedRenterData = TU.exportDriverData(driverFileName);
				if(exportedRenterData.size() == 0)
				{
					cout << "Export Unsuccessful, Reason:(wrong file name / empty file)." << endl;
				}
				else
				{
					cout << "Export Successful." << endl;
					renterExportFlag = true;
				}
				cout << "#######################################################" << endl;

			}
			if(innerChoice == 2)
			{
				cout << "Enter the name of the file (.csv):" << endl;
				cout << "#######################################################" << endl;
				cin >> carFileName;
				cout << "#######################################################" << endl;
				exportedCarData = TU.exportCarData(carFileName);
				if (exportedCarData.size() == 0)
				{
					cout << "Export Unsuccessful, Reason:(wrong file name / empty file)." << endl;
				}
				else
				{
					cout << "Export Successful." << endl;
					carExportFlag = true;
				}
				cout << "#######################################################" << endl;
			}
		}
		else if (choice == 2)
		{
			if (renterExportFlag != false) 
			{
				string ID, name, age, gender, LNo;
				cout << "Enter Driver's ID:" << endl;
				cin.ignore();
				getline(cin, ID);
				cout << "-------------------------------------------" << endl;
				cout << "Enter Driver's Name:" << endl;
				getline(cin, name);
				cout << "-------------------------------------------" << endl;
				cout << "Enter Driver's Age:" << endl;
				getline(cin, age);
				cout << "-------------------------------------------" << endl;
				cout << "Enter Driver's Gender:" << endl;
				getline(cin, gender);
				cout << "-------------------------------------------" << endl;
				cout << "Enter Driver's License Number:" << endl;
				getline(cin, LNo);
				cout << "-------------------------------------------" << endl;
				cout << "Renter added successfully." << endl;
				cout << "#######################################################" << endl;
				MU.addRenter(driverFileName, ID, name, age, gender, LNo);
			}
			else
			{
				cout << "Data must be exported from a valid file to do any action.\nExport data from the first option." << endl;
				cout << "#######################################################" << endl;
			}
		}
		else if (choice == 3)
		{
			if (carExportFlag != false)
			{
				string plateNo, owner;
				cout << "Enter Car's Plate ID:" << endl;
				cin.ignore();
				getline(cin, plateNo);
				cout << "-------------------------------------------" << endl;
				cout << "Enter Car's owner:" << endl;
				getline(cin, owner);
				cout << "-------------------------------------------" << endl;
				cout << "Car added successfully." << endl;
				cout << "#######################################################" << endl;
				MU.addCar(carFileName, plateNo, owner, "No Renter");
			}
			else
			{
				cout << "Data must be exported from a valid file to do any action.\nExport data from the first option." << endl;
				cout << "#######################################################" << endl;
			}

		}
		else if (choice == 4)
		{
			if(renterExportFlag != false)
			{
				string ID;
				bool renterFound = false;
				cout << "Enter Driver's ID:" << endl;
				cin.ignore();
				getline(cin, ID);
				cout << "-------------------------------------------" << endl;
				for(int i = 0 ; i < exportedRenterData.size(); i++)
				{
					if(exportedRenterData[i].getID() == ID)
					{
						renterFound = true;
					}
				}
				if (renterFound == true)
				{
					MU.removeRenter(driverFileName, ID);
					cout << "renter removed successfully." << endl;
					cout << "#######################################################" << endl;
				}
				else
				{
					cout << "Renter not found in the system.\nMake sure you type the Driver's ID correctly." << endl;
					cout << "#######################################################" << endl;
				}
			}
			else
			{
				cout << "Data must be exported from a valid file to do any action.\nExport data from the first option." << endl;
				cout << "#######################################################" << endl;
			}
		}
		else if (choice == 5)
		{
			if (carExportFlag != false)
			{
				string plateNo;
				bool carFound = false;
				cout << "Enter Car's Plate Number:" << endl;
				cin.ignore();
				getline(cin, plateNo);
				cout << "-------------------------------------------" << endl;
				for (int i = 0; i < exportedCarData.size(); i++)
				{
					if (exportedCarData[i].getPlateNumber() == plateNo)
					{
						carFound = true;
					}
				}
				if (carFound == true)
				{
					MU.removeCar(carFileName, plateNo);
					cout << "Car removed successfully." << endl;
					cout << "#######################################################" << endl;
				}
				else
				{
					cout << "Car not found in the system.\nMake sure you type the Car's ID correctly." << endl;
					cout << "#######################################################" << endl;
				}
			}
			else
			{
				cout << "Data must be exported from a valid file to do any action.\nExport data from the first option." << endl;
				cout << "#######################################################" << endl;
			}
		}
		else if (choice == 6)
		{
			if(carExportFlag != false)
			{
				vector<carData> availableCars = DU.returnAvailableCars(carFileName);
				cout << "-------------------------------------------" << endl;
				if(availableCars.size() != 0)
				{
					for (int i = 0; i < availableCars.size(); i++)
					{
						cout << "Car's Plate Number:" << endl;
						cout << availableCars[i].getPlateNumber() << endl;
						cout << "Car's Owner:" << endl;
						cout << availableCars[i].getOwner() << endl;
						cout << "-------------------------------------------" << endl;
					}
				}
				else
				{
					cout << "No Car(s) is/are available for rent found in the system.\nCome Again Later." << endl;
					cout << "#######################################################" << endl;
				}
			}
			else
			{
				cout << "Data must be exported from a valid file to do any action.\nExport data from the first option." << endl;
				cout << "#######################################################" << endl;
			}
		}
		else if(choice == 7) 
		{
			if (carExportFlag != false)
			{
				vector<carData> RentedCars = DU.returnRentedCars(carFileName);
				cout << "-------------------------------------------" << endl;
				if (RentedCars.size() != 0)
				{
					for (int i = 0; i < RentedCars.size(); i++)
					{
						cout << "Car's Plate Number:" << endl;
						cout << RentedCars[i].getPlateNumber() << endl;
						cout << "Car's Owner:" << endl;
						cout << RentedCars[i].getOwner() << endl;
						cout << "Car's Current Renter" << endl;
						cout << RentedCars[i].getRenter() << endl;
						cout << "-------------------------------------------" << endl;
					}
				}
				else
				{
					cout << "No Car(s) is/are rented found in the system." << endl;
					cout << "#######################################################" << endl;
				}
			}
			else
			{
				cout << "Data must be exported from a valid file to do any action.\nExport data from the first option." << endl;
				cout << "#######################################################" << endl;
			}
		}
		else if(choice == 8)
		{
			if(carExportFlag != false && renterExportFlag != false)
			{
				string ID, plateNo;
				cout << "Enter Renter's ID:" << endl;
				cin.ignore();
				getline(cin, ID);
				cout << "-------------------------------------------" << endl;
				cout << "Enter Car's Plate Number:" << endl;
				getline(cin, plateNo);
				cout << "-------------------------------------------" << endl;
				int rentState = CRM.DBRent(driverFileName, carFileName, ID, plateNo);
				if(rentState == 1)
				{
					cout << "Car rented successfully." << endl;
					cout << "#######################################################" << endl;
				}
				else if(rentState == 2)
				{
					cout << "Unknown Car and Renter.\n Add them from option 2 and 3." << endl;
					cout << "#######################################################" << endl;
				}
				else if(rentState == -1)
				{
					cout << "Unknown Car.\n Add it from option 3." << endl;
					cout << "#######################################################" << endl;
				}
				else if(rentState == 0)
				{
					cout << "Unknown Renter.\n Initiating Adding new Renter to the DB." << endl;
					cout << "#######################################################" << endl;
					string ID, name, age, gender, LNo;
					cout << "Enter Driver's ID:" << endl;
					cin.ignore();
					getline(cin, ID);
					cout << "-------------------------------------------" << endl;
					cout << "Enter Driver's Name:" << endl;
					getline(cin, name);
					cout << "-------------------------------------------" << endl;
					cout << "Enter Driver's Age:" << endl;
					getline(cin, age);
					cout << "-------------------------------------------" << endl;
					cout << "Enter Driver's Gender:" << endl;
					getline(cin, gender);
					cout << "-------------------------------------------" << endl;
					cout << "Enter Driver's License Number:" << endl;
					getline(cin, LNo);
					cout << "-------------------------------------------" << endl;
					CRM.nonDBRent(driverFileName, carFileName, ID, name, age, gender, LNo, plateNo);
					cout << "-------------------------------------------" << endl;
					cout << "Renter added to the DB and succesfully rented the Car." << endl;
					cout << "#######################################################" << endl;
				}
			}
			else
			{
				cout << "Data must be exported from a valid file to do any action.\nExport data from the first option." << endl;
				cout << "#######################################################" << endl;
			}
		}
	}
	system("pause");
}