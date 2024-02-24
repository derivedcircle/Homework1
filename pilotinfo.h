#ifndef PILOT_H
#define PILOT_H
// include guard using keyword PILOT_H

#include<iostream>
#include<string>
#include "planeinfo.h"
#include<memory>
using namespace std;
// including all relevant libraries and setting default namespace as standard

// much of this code is set up in accordance to instructions from q6
class Pilot {
	string name;
	
	public:
	// constructor and destructors
	Pilot(string namein);
	~Pilot();
	
	// function to output the name of the pilot
	string getName();
	
	// public varible holding the reference to an assigned plane
	Plane* myPlane;
	// This funciton was additionally added to help minimize code reuse by also sending the nessisary
	// print instrucitons during plane reassignment
	void setPlane(Plane* myPlanein);

	shared_ptr<Plane> myNewPlane;// this varible is used in question 8 to allow the code to opperate with 
	// new C++ smart pointers (see q8 instructions)
};

#endif