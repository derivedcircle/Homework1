#include<iostream>
#include<string>


using namespace std;

// question 7


Pilot::Pilot(string namein)
{
	name = namein;// stored inputted name and prints out a ready to go message to console
	cout << "Pilot " << name << " with certificate number " << this << " is at the gate, ready to board the plane.";
}

Pilot::~Pilot()
{
	cout << "Pilot " << name << " is out of the plane.";
	//destructor that outputs a message to console
}

// function that returns pilot's name.
string Pilot::getName()
{
	return name;
}

