#include <string>
#include <iostream>
#include "renter.h"
using namespace std;

renter::renter(string id, string n, string a, string g, string ln)
{
	nationalID = id;
	name = n;
	age = a;
	gender = g;
	licenceNumber = ln;
}

string renter::getID()
{
	return nationalID;
}

void renter::setID(string id)
{
	nationalID = id;
}

string renter::getName()
{
	return name;
}

void renter::setName(string n)
{
	name = n;
}

string renter::getAge()
{
	return age;
}

void renter::setAge(string a)
{
	age = a;
}

string renter::getGender()
{
	return gender;
}

void renter::setGender(string g)
{
	gender = g;
}

string renter::getLNo()
{
	return licenceNumber;
}

void renter::setLNo(string lno)
{
	licenceNumber = lno;
}
