#pragma once
#include <iostream>
using namespace std;
class renter
{
	// renter properties:
	string nationalID;
	string name;
	string age;
	string gender;
	string licenceNumber;
public:
	renter(string, string, string, string, string);
	
	string getID();
	void setID(string);

	string getName();
	void setName(string);

	string getAge();
	void setAge(string);

	string getGender();
	void setGender(string);

	string getLNo();
	void setLNo(string);
};

