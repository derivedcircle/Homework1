#include<iostream>
#include <string>
#include <vector>
#include<numeric>
#include "part1.h"
#include <map>


using namespace std;

int main()
{
  //bool safe = part1();
  //cout << "The aircraft is " << safe << endl;
  //part1();


  // part 2
  map<string, double> destinationsSCE; // creates a map of values where the destinaion is the key and the distance in miles is the values mapped to
  // this information is from part 2 of the homework 1 information
  destinationsSCE["PHL"] = 160; 
  destinationsSCE["ORD"] = 640;
  destinationsSCE["EWR"] = 220;

  
  return 0;
}