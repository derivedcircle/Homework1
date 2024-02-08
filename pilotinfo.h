#include<iostream>
#include<string>
#include "planeinfo.h"
#include<memory>
// question 6
using namespace std;

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
	void setPlane(Plane* myPlanein);

	weak_ptr<Plane> myNewPlane;
};