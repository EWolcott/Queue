///////////////////////////////////////////////////////////////////////////////
// Group: <ID>
// Names: <First_Name> <Last_Name>, <First_Name> <Last_Name>
// Date: <Date>
// Course Code: CS-273-<X>
//
// License: CS172 students at whitworth may edit this file but not share this 
// file electronically with other students.
//
// Copyright (C) <Your Name Here> 2020 - 2021
// Derived from work by Scott Griffith
//
// Resources used: <Enter and external citations needed>
// Collaborators: <If you worked with others place their name here> 
//
// Elevator simulation utilizing queues.
//
///////////////////////////////////////////////////////////////////////////////

#include "person.h"
#include "elevator.h"
#include "building.h"

#include <iostream> // Couting
#include <cstdlib>  // Seeding random number
#include <ctime>    // Help seeding srand()

using std::cout;
using std::endl;

int main(){
    // !!!! For debugging, you might want to comment out the time(NULL) !!!!
    srand(time(NULL));
    //srand(0);

    // Initialize ID pool for Person class
    Person::setIDPool(1);

    //Make a new building! The Eric Johnston Science Center
    Building ejsc;
    int pCount = 0;
    int upperLimit = 50; //Test for 50 people

    //Get some people in line for the elevator
    ejsc.generatePassenger();
    ejsc.generatePassenger();
    ejsc.generatePassenger();
    ejsc.generatePassenger();
    ejsc.generatePassenger();

    //Loop until the elevator has finished processing
    while(ejsc.processElevator()){
        //Diagnostic print
        ejsc.print();

        //Random determination if a new person should be included
        if((rand()%60) && (pCount < upperLimit) ){
            ejsc.generatePassenger();
            pCount++;
        }
    }

    //Once finished, print out the stats for the elevator
    ejsc.printStats();
}*/