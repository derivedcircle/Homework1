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

	// setting standard values used for all 3 sets of flight tracking

	double velocitystandard = 450;//mph standard velocity used throughout rest of code
	double timestepstandard = 15.0;//seconds standard timestep used throughout rest of code
	int maxitters = 2000;// sets the maximum number of itterations for the for loops in rest of code


	{// parts 2-5 (using braces to limit scope)

		// setting up an aircraft that flies between newark and state college
		Plane newarkbound("EWR", "SCE");
		newarkbound.setVel(velocitystandard);
		cout << "Parts 2-5, Aircraft in transit" << endl;
		cout << "----------------------------" << endl;

		for (int i = 0; i < maxitters; i++)// starts for loop for 1000 itterations of the opperate command
		{
			newarkbound.operate(timestepstandard / 3600); // steps aircraft forward by 10 seconds
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
		chicagobound.setVel(velocitystandard);
		// setting alpha as the initial pilot flying
		pilalpha.setPlane(&chicagobound);
		pilbravo.setPlane(NULL);

		// loop for regular plane opperation
		for (int i = 0; i < maxitters; i++)// starts for loop for 1000 itterations of the opperate command
		{
			chicagobound.operate(timestepstandard / 3600); // steps aircraft forward by 10 seconds
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

	
	{// questions 8 (using braces to limit scope)

		//q8 creating 2 pilots and their plane flying between state college and philidelphia
		cout << "Part 8, Pilots flying Aircraft in transit ~ New School" << endl;
		cout << "---------------------------------------------------------" << endl;
		Pilot pilcharlie("Charlie");
		Pilot pildelta("Delta");
		
		// creates the reference to the phillybound plane
		shared_ptr<Plane> phillyboundRef = make_shared<Plane>("SCE", "PHL");

		//sets velocity for phillybound plane
		phillyboundRef->setVel(velocitystandard);

		// setting charlie as the origional pilot flying
		pilcharlie.myNewPlane = phillyboundRef;
		pildelta.myNewPlane = nullptr;
		
		

		// loop for regular plane opperation
		for (int i = 0; i < maxitters; i++)// starts for loop for 1000 itterations of the opperate command
		{
			phillyboundRef->operate(timestepstandard / 3600); // steps aircraft forward by 15 seconds
			
			// outputs time since start in seconds and the aircraft position (for debugging)
			//cout << "Time: " << i * 15.0 << " seconds, Position: " << phillyboundRef->getPos() << " miles." << endl;
			if (phillyboundRef->getAt_SCE())// prints if the aircraft is at state college
			{
				cout << endl << "The plane " << phillyboundRef << " is at SCE at Time: " << i * 15.0 << " seconds." << endl;
				if (!(pildelta.myNewPlane))// this if statement tree swapps the PILOT in Command
				{
					
					swap(pildelta.myNewPlane, pilcharlie.myNewPlane);// swaps the refrences for the two pilots
					cout << "Pilot " << pildelta.getName() << " with certificate number " << &pildelta << " is in control of plane: " 
						<< pildelta.myNewPlane << endl;
					
					cout << "Pilot " << pilcharlie.getName() << " with certificate number " << &pilcharlie << " is in control of plane: "
						<< pilcharlie.myNewPlane << endl;
				}
				else if (!(pilcharlie.myNewPlane))
				{
					
					swap(pildelta.myNewPlane, pilcharlie.myNewPlane);// swaps the refrences for the two pilots
					cout << "Pilot " << pilcharlie.getName() << " with certificate number " << &pilcharlie << " is in control of plane: "
						<< pilcharlie.myNewPlane << endl;
					
					cout << "Pilot " << pildelta.getName() << " with certificate number " << &pildelta << " is in control of plane: "
						<< pildelta.myNewPlane << endl;
				}
			}



		}

	}
  
  return 0;
}