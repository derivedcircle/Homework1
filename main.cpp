#include<iostream>
#include <string>
#include <vector>
#include<numeric>
#include "part1.h"
#include <map>
#include "planeinfo.h"



using namespace std;

int main()
{
  //bool safe = part1();
  //cout << "The aircraft is " << safe << endl;
  //part1();

	// setting up an aircraft that flies between newark and state college
	Plane newarkbound("EWR","SCE");
	newarkbound.setVel(450);
	cout << "Parts 2-5, Aircraft in transit" << endl;
	cout << "----------------------------" << endl;

	for (int i = 0; i < 1000; i++)// starts for loop for 1000 itterations of the opperate command
	{
		newarkbound.operate(15.0 / 3600); // steps aircraft forward by 10 seconds
		// outputs time since start in seconds and the aircraft position
		cout << "Time: " << i * 15.0 << " seconds, Position: " << newarkbound.getPos() << " miles." << endl;
		if (newarkbound.getAt_SCE())// prints if the aircraft is at state college (for debugging)
			cout << "Currently at state college" << endl;
		
		
	}


	
  
  return 0;
}