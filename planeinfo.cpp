#include<iostream>
#include<map>
#include<vector>
#include<string>

//#include "planeinfo.h"
using namespace std;

class Plane {
	double pos;
	double vel;
	bool at_SCE;
	map<string, double> destinationsSCE; // creates a map of values where the destinaion is the key and the distance in miles is the values mapped to
	// this information is from part 2 of the homework 1 information
	//destinationsSCE["PHL"] = 160;
	//destinationsSCE["ORD"] = 640;
	//destinationsSCE["EWR"] = 220;
};