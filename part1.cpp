#include "part1.h"
#include<iostream>
#include <string>
#include <vector>
#include<numeric>
using namespace std;
//including relevant libraries and setting std as a default namespace

double enterval(string prompt)// function that takes a prompt input and returns the requested output (used as a macro for convenience)
{
  cout << "Enter the " << prompt <<": ";

  double var;

  cin >> var;

  return var;
} // this function is not in the part 1 header file as it is only intended to be accesable in this file


bool part1() // starting function to run through collecting the perameters of the aircraft,
{// calculating the weight and CG of the aircraft and returning a boolean for if the aircraft is safe to fly
  
    //starting sequence
    cout << "Part 1, Aircraft Parameters" << endl;
    cout << "----------------------------" << endl;

    cout << "Enter the following parameters for a plane:" << endl;

    //asking for all requested values from part 1 using enterval as a function macro
    double emptyWeight = enterval("airplane's empty weight (lbs)");
    double emptyWeightMom = enterval("airplane's empty weight moment (lbs-in)");

    // this gets the weights of all of the passengers in the front using a for loop stores them into a vector
    int numOfFrontSeat = enterval("number of front seat occupants");

    vector<double> frontSeatWeights;
    for (int i = 0; i < numOfFrontSeat; i++)
    {
        frontSeatWeights.push_back(enterval("weight (lbs) of front seat occupant number " + to_string(i+1)));
    }
    double frontSeatMomArm = enterval("moment arm of front seat occupants (in)");


    // this gets the weights of all of the passengers in the rear using a for loop stores them into a vector
    int numOfRearSeat = enterval("number of rear seat occupants");
    vector<double> rearSeatWeights;
    for (int i = 0; i < numOfRearSeat; i++)
    {
        rearSeatWeights.push_back(enterval("weight (lbs) of rear seat occupant number " + to_string(i+1)));
    }
    double rearSeatMomArm = enterval("moment arm of rear seat occupants (in)");

    //gets the volume, weight per volume, and moment arm of the fuel in the aircraft
    double fuelVol = enterval("usable fuel volume (gal)");
    double fuelWeightperGal = enterval("fuel weight per gallon (lbs/gal)");
    double fuelMomArm = enterval("moment arm of fuel (in)");

    //gets the baggage weight and moment arm for the aircraft
    double BaggageWeight = enterval("baggage weight (lbs)");
    double BaggageMomArm = enterval("moment arm of baggage (in)");


    // calculations (accumulate function adds all values in the vector)
    double totalWeight = emptyWeight + accumulate(frontSeatWeights.begin(), frontSeatWeights.end(), 0.0) + accumulate(rearSeatWeights.begin(), rearSeatWeights.end(), 0.0) + fuelWeightperGal * fuelVol + BaggageWeight;
    // calculating the total weight by adding up the weight of all individual components of the plane
    double totalMomArm = emptyWeightMom + accumulate(frontSeatWeights.begin(), frontSeatWeights.end(), 0.0)*frontSeatMomArm + accumulate(rearSeatWeights.begin(), rearSeatWeights.end(), 0.0)*rearSeatMomArm + fuelWeightperGal * fuelVol*fuelMomArm + BaggageWeight*BaggageMomArm;
    // calculating the moment arm by adding the empty moment of the plane to the weight of each component of the aircraft
    // multiplied by its moment arm

    // calculates the center of gravity of the aircraft
    double centerOfGravity = totalMomArm/totalWeight;
  
    //output
    cout << "The weight of the aircraft is " << totalWeight << " pounds." << endl;
    cout << "The center of gravity of the aircraft is " << centerOfGravity << " inches" << endl;

    // checking to see if the aircraft is opperating in its opperating perameters
    bool isSafe;
  
  
    if (totalWeight < 2950 && (centerOfGravity > 82.1 && centerOfGravity < 84.7))// checks if aircraft perameters are in design limits
        isSafe = true;
    else
        isSafe = false;

    // returns boolean value for if the aircraft is safe or not
    return isSafe;
}

