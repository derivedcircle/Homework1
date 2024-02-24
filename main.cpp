#include<iostream>
#include <string>
#include <vector>
#include<numeric>
#include "part1.h"
#include <map>
#include "planeinfo.h"
#include "pilotinfo.h"
#include<memory>



using namespace std;
// including all relevant libraries and setting default namespace to standard


int main()
{
	
	{// part 1 (using braces to limit scope)
		bool planeSafe = part1();// asks for aircraft data and saves a boolean for if the aircraft is safe or not
		if (planeSafe)
			cout << "The plane is safe" << endl;
		else
			cout << "The plane exceeds CG or Weight limits" << endl;
	}
	
	cout << endl;// creates space between sections for reading clarity

	// setting standard values used for all 3 sets of flight tracking (in q5.q7 and q8)

	double velocitystandard = 450;//mph standard velocity used throughout rest of code
	double timestepstandard = 15.0;//seconds standard timestep used throughout rest of code
	int maxitters = 1000;// sets the maximum number of itterations for the for loops in rest of code


	{// parts 2-5 (using braces to limit scope)

		// setting up an aircraft that flies between newark and state college
		cout << "Questions 2-5, Aircraft in transit" << endl;
		cout << "----------------------------" << endl;
		// the following code is relevant to instructions from q5

		Plane newarkbound("EWR", "SCE");
		
		newarkbound.setVel(velocitystandard);// sets velocity at 450 (standard velocity used throughout the code)
		

		for (int i = 0; i < maxitters; i++)// starts for loop for 1000 itterations of the opperate command
		{
			// outputs time since start in seconds and the aircraft position
			cout << "Time: " << i * 15.0 << " seconds, Position: " << newarkbound.getPos() << " miles." << endl;
			
			newarkbound.operate(timestepstandard / 3600); // steps aircraft forward by 15 seconds (dt is in hours so the timestep value
			// is devided by 3600 to convert from seconds to hours)
			
			
			
		}
	}
	
	cout << endl;// creates space between sections for reading clarity

	{// questions 6 and 7 (using braces to limit scope)

		// Creating 2 pilots and their plane flying between state college and chicago using the old C++ style pointers
		cout << "Questions 6-7, Pilots flying Aircraft in transit ~ Old School" << endl;
		cout << "---------------------------------------------------------" << endl;
		// The following code is relevant to q7

		// initialising our two pilots (Alpha and Bravo)
		Pilot pilalpha("Alpha");
		Pilot pilbravo("Bravo");
		Plane chicagobound("SCE", "ORD");// initializing plane flying to Chicago
		chicagobound.setVel(velocitystandard); // sets velocity at 450 (standard velocity used throughout the code)
		// setting alpha as the initial pilot flying
		// by storing the reference to the chicagobound plane to the pilot's myPlane Plane pointer varible
		pilalpha.setPlane(&chicagobound);
		pilbravo.setPlane(NULL); // Bravo's plane is null

		// loop for regular plane opperation
		for (int i = 0; i < maxitters; i++)// starts for loop for 1000 itterations of the opperate command
		{
			chicagobound.operate(timestepstandard / 3600); // steps aircraft forward by 15 seconds (dt is in hours so the timestep value
			// is devided by 3600 to convert from seconds to hours)
			

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
	cout << endl;// creates space between sections for reading clarity

	
	{// questions 8 (using braces to limit scope)

		//q8 creating 2 pilots and their plane flying between state college and philidelphia using the new C++ smart pointer style
		cout << "Question 8, Pilots flying Aircraft in transit ~ New School" << endl;
		cout << "---------------------------------------------------------" << endl;
		// the following code is relevant to q8 and its instructions
		// this section is very similar to the above section but uses smart pointers instead of raw pointers like the previous section

		// initialising our two pilots (Charlie and Delta)
		Pilot pilcharlie("Charlie");
		Pilot pildelta("Delta");
		
		// creates the shared pointer to the phillybound plane (stored dynamically)
		shared_ptr<Plane> phillyboundRef = make_shared<Plane>("SCE", "PHL");

		//sets velocity for phillybound plane
		phillyboundRef->setVel(velocitystandard);// sets velocity at 450 (standard velocity used throughout the code)

		// setting charlie as the initial pilot flying
		// by storing the smart pointer to the phillybound plane to the pilot's myNewPlane Plane shared pointer varible
		pilcharlie.myNewPlane = phillyboundRef;
		pildelta.myNewPlane = nullptr;
		
		// prints out which pilot is initially in control of the phillybound plane and the null plane (not in control of a plane)
		cout << "Pilot " << pilcharlie.getName() << " with certificate number " << &pilcharlie << " is in control of plane: "
			<< pilcharlie.myNewPlane << endl;

		cout << "Pilot " << pildelta.getName() << " with certificate number " << &pildelta << " is in control of plane: "
			<< pildelta.myNewPlane << endl;

		// loop for regular plane opperation
		for (int i = 0; i < maxitters; i++)// starts for loop for 1000 itterations of the opperate command
		{
			phillyboundRef->operate(timestepstandard / 3600); // steps aircraft forward by 15 seconds (dt is in hours so the timestep value
			// is devided by 3600 to convert from seconds to hours)
			
			
			if (phillyboundRef->getAt_SCE())// prints if the aircraft is at state college
			{
				cout << endl << "The plane " << phillyboundRef << " is at SCE at Time: " << i * 15.0 << " seconds." << endl;
				if (!(pildelta.myNewPlane))// this if statement tree swapps the PILOT in Command
				{
					
					swap(pildelta.myNewPlane, pilcharlie.myNewPlane);// swaps the plane refrences for the two pilots' myNewPlane varible

					// prints out which pilot is in control of the phillybound plane and the null plane (not in control of a plane)
					cout << "Pilot " << pildelta.getName() << " with certificate number " << &pildelta << " is in control of plane: " 
						<< pildelta.myNewPlane << endl;
					
					cout << "Pilot " << pilcharlie.getName() << " with certificate number " << &pilcharlie << " is in control of plane: "
						<< pilcharlie.myNewPlane << endl;
				}
				else if (!(pilcharlie.myNewPlane))
				{
					
					swap(pildelta.myNewPlane, pilcharlie.myNewPlane);// swaps the plane refrences for the two pilots' myNewPlane varible

					// prints out which pilot is in control of the phillybound plane and the null plane (not in control of a plane)
					cout << "Pilot " << pilcharlie.getName() << " with certificate number " << &pilcharlie << " is in control of plane: "
						<< pilcharlie.myNewPlane << endl;
					
					cout << "Pilot " << pildelta.getName() << " with certificate number " << &pildelta << " is in control of plane: "
						<< pildelta.myNewPlane << endl;
				}
			}



		}

	}
  
  return 0; // FIN (the end of the code)
}