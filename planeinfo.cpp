#include<iostream>
#include<map>
#include<vector>
#include<string>

#include "planeinfo.h"
using namespace std;

Plane::Plane(string from,string to)// plane constructor
{
	origin = from;
	destination = to;
	// setting up all of the distance shit using the information from container from q2
	destinationsSCE["PHL"] = 160.0;
	destinationsSCE["ORD"] = 640.0;
	destinationsSCE["EWR"] = 220.0;
	if (origin == "SCE")
		distance = destinationsSCE[destination];
	else
		distance = destinationsSCE[origin];

	// initializing pos,vel,at_sce to 0 as per q4 instructions
	
	pos = 0.0;
	vel = 0.0;
	at_SCE = false;

	// a print statement including the memory address of the plane
	cout<<"Plane created with a tail number "<< this << endl;
}

//destructor
Plane::~Plane()
{
	cout << "Plane Destroyed" << endl;
}

void Plane::operate(double dt)
{
	if (pos < distance)
	{
		pos += vel * dt;// changing position over time
		at_SCE = false;
	}
	else if (destination == "SCE")
	{
		at_SCE = true;

		//swapping value of origin and destination
		string holder = origin;
		origin = destination;
		destination = holder;

		// resetting position
		pos = 0.0;

	}
	else
	{
		//swapping value of origin and destination
		string holder = origin;
		origin = destination;
		destination = holder;

		// resetting position
		pos = 0.0;
	}
}

double Plane::getPos()
{
	return pos;
}


string Plane::getOrigin()
{
	return origin;
}

string Plane::getDestination()
{
	return destination;
}

bool Plane::getAt_SCE()
{
	return at_SCE;
}

double Plane::getVel()
{
	return vel;
}

void Plane::setVel(double velin)
{
	vel = velin;
}