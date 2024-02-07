#include<iostream>
#include<map>
#include<vector>
#include<string>
// question 3
using namespace std;

class Plane {
	double pos;
	double vel;
	double distance;
	bool at_SCE;
	map<string, double> destinationsSCE;
	string origin;
	string destination;
	
	public:
	
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