#ifndef PLANE_H
#define PLANE_H
// include guard using keyword PLANE_H

#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
// including all relevant libraries and setting default namespace as standard

// The class is set up in accordance of the instructions for question 3
class Plane {// initializing class Plane
	// all private varibles nessisary for opperation of plane class
	double pos;
	double vel;
	double distance;
	bool at_SCE;
	map<string, double> destinationsSCE; // this is the container from question 2
	string origin;
	string destination;
	
	public:
	// all public functions and varibles needed to operate plane class
	Plane(string from, string to);
	~Plane();
	void operate (double dt);
	double getPos();
	string getOrigin();
	string getDestination();
	bool getAt_SCE();
	double getVel();
	void setVel(double velin);
	
};

#endif