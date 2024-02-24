#include<iostream>
#include<map>
#include<vector>
#include<string>
#include "planeinfo.h"
using namespace std;
// including all relevant libraries and setting default namespace to standard

// This file contains code mostly relevant to question 4
Plane::Plane(string from,string to)// plane constructor
{
	origin = from;
	destination = to;
	// setting up all of the distances for each destination using the information from container from question 2 (as requested in question 2)
	destinationsSCE["PHL"] = 160.0;
	destinationsSCE["ORD"] = 640.0;
	destinationsSCE["EWR"] = 220.0;
	
	// This checks if the origin is SCE or not as to find the distance to the destination, the code must use the other airport code as 
	// this is how destinationsSCE is configured (it requires the other airport code)
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

void Plane::operate(double dt) // function handles aircraft movement (see flowchart for function opperations in q4)
{
	if (pos < distance)
	{
		// if the pos is less than the distance to destination, incriment the position by the timestep and set at_SCE to false (in transit)

		pos += vel * dt;// changing position over time
		at_SCE = false;
	}
	else if (destination == "SCE")
	{
		at_SCE = true;//sets at_SCE to true as the aircraft has arrived at SCE

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

double Plane::getPos()//returns the position of the aircraft
{
	return pos;
}


string Plane::getOrigin()//returns the origin of the aircraft
{
	return origin;
}

string Plane::getDestination()//returns the destination of the aircraft
{
	return destination;
}

bool Plane::getAt_SCE()//returns if the aircraft is at State College
{
	return at_SCE;
}

double Plane::getVel()//returns the velocity of the aircraft
{
	return vel;
}

void Plane::setVel(double velin)// sets the aircraft's velocity
{
	vel = velin;
}