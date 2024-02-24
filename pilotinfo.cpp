#include<iostream>
#include<string>
#include "pilotinfo.h"
using namespace std;
// including all relevant libraries and setting default namespace to standard

// This file contains code mostly relevant to question 6 and 7


Pilot::Pilot(string namein)// pilot constructor
{
	name = namein;// stored inputted name and prints out a ready to go message to console
	cout << "Pilot " << name << " with certificate number " << this << " is at the gate, ready to board the plane." << endl;
}

Pilot::~Pilot()// Pilot destructor
{
	cout << "Pilot " << name << " is out of the plane." << endl;
	//destructor that outputs a message to console
}

// function that returns pilot's name.
string Pilot::getName()
{
	return name;
}

// sets the new Plane when reassigning planes for pilots
// This funciton was additionally added to help minimize code reuse by also sending the nessisary
// print instrucitons during plane reassignment
void Pilot::setPlane(Plane* myPlanein)
{
	myPlane = myPlanein;
	cout << "Pilot " << name << " with certificate number " << this << " is in control of plane: " << myPlane << endl;// this is that 
	// nessisary pring statement
}
