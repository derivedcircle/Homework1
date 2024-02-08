#include<iostream>
#include<string>
#include "pilotinfo.h"

using namespace std;

// question 7


Pilot::Pilot(string namein)
{
	name = namein;// stored inputted name and prints out a ready to go message to console
	cout << "Pilot " << name << " with certificate number " << this << " is at the gate, ready to board the plane." << endl;
}

Pilot::~Pilot()
{
	cout << "Pilot " << name << " is out of the plane." << endl;
	//destructor that outputs a message to console
}

// function that returns pilot's name.
string Pilot::getName()
{
	return name;
}

// sets the new Plane when reassigning planes for pilots (may remove)
void Pilot::setPlane(Plane* myPlanein)
{
	myPlane = myPlanein;
	cout << "Pilot " << name << " with certificate number " << this << " is in control of plane: " << myPlane << endl;
}
