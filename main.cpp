#include<iostream>
#include <string>
#include <vector>
#include<numeric>
#include "part1.h"
#include <map>
//#include "planeinfo.h"
#include "pilotinfo.h"
#include<memory>



using namespace std;

int main()
{
  //bool safe = part1();
  //cout << "The aircraft is " << safe << endl;
  //part1();
	{// parts 2-5 (using braces to limit scope)

		// setting up an aircraft that flies between newark and state college
		Plane newarkbound("EWR", "SCE");
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
	}
	
	cout << endl;
	{// questions 6 and 7 (using braces to limit scope)

		//q7 creating 2 pilots and their plane flying between state college and chicago
		cout << "Parts 6-7, Pilots flying Aircraft in transit ~ Old School" << endl;
		cout << "---------------------------------------------------------" << endl;
		Pilot pilalpha("Alpha");
		Pilot pilbravo("Bravo");
		Plane chicagobound("SCE", "ORD");
		chicagobound.setVel(450);
		// setting alpha as the initial pilot flying
		pilalpha.setPlane(&chicagobound);
		pilbravo.setPlane(NULL);

		// loop for regular plane opperation
		for (int i = 0; i < 2000; i++)// starts for loop for 1000 itterations of the opperate command
		{
			chicagobound.operate(15.0 / 3600); // steps aircraft forward by 10 seconds
			// outputs time since start in seconds and the aircraft position (for debugging)
			// << "Time: " << i * 15.0 << " seconds, Position: " << chicagobound.getPos() << " miles." << endl;
			if (chicagobound.getAt_SCE())// prints if the aircraft is at state college
			{
				cout << endl << "The plane " << &chicagobound << " is at SCE at Time: " << i * 15.0 << " seconds." << endl;
				if (pilbravo.myPlane == NULL)// this if statement tree swapps the PILOT in Command
				{
					pilbravo.setPlane(&chicagobound);
					pilalpha.setPlane(NULL);
				}
				else if (pilalpha.myPlane == NULL)
				{
					pilalpha.setPlane(&chicagobound);
					pilbravo.setPlane(NULL);
				}
			}



		}

	}
	cout << endl;

	/*
	{// questions 8 (using braces to limit scope)

		//q8 creating 2 pilots and their plane flying between state college and philidelphia
		cout << "Part 8, Pilots flying Aircraft in transit ~ New School" << endl;
		cout << "---------------------------------------------------------" << endl;
		Pilot pilcharlie("Charlie");
		Pilot pildelta("Delta");
		Plane phillybound("SCE", "PHL");
		phillybound.setVel(450);
		// setting alpha as the initial pilot flying
		pilcharlie.myNewPlane = make_unique<Plane>(phillybound);
		//pilcharlie.myNewPlane 
		pildelta.myNewPlane = make_unique<Plane>(NULL);

		// loop for regular plane opperation
		for (int i = 0; i < 2000; i++)// starts for loop for 1000 itterations of the opperate command
		{
			phillybound.operate(15.0 / 3600); // steps aircraft forward by 15 seconds
			// outputs time since start in seconds and the aircraft position (for debugging)
			// << "Time: " << i * 15.0 << " seconds, Position: " << chicagobound.getPos() << " miles." << endl;
			if (phillybound.getAt_SCE())// prints if the aircraft is at state college
			{
				cout << endl << "The plane " << &phillybound << " is at SCE at Time: " << i * 15.0 << " seconds." << endl;
				if (pildelta.myPlane == NULL)// this if statement tree swapps the PILOT in Command
				{
					pildelta.myNewPlane = make_unique<Plane>(phillybound);
					pilcharlie.myNewPlane = make_unique<Plane>(NULL);
				}
				else if (pilcharlie.myPlane == NULL)
				{
					pilcharlie.myNewPlane = make_unique<Plane>(phillybound);
					pildelta.myNewPlane = make_unique<Plane>(NULL);
				}
			}



		}

	}*/
  
  return 0;
}