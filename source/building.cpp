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
// Building implementation for queue application
//
///////////////////////////////////////////////////////////////////////////////

#include "building.h"
#include "queue.h"

#include <iostream>
using std::cout;
using std::endl;

Building::Building(){
    //Initializing each floor to have a queue.
    for(int i = 0; i <= MAX_FLOOR; i++){
        floors.push_back( queue< Person , b_container> () );
    }
}

bool Building::processElevator(){
    //If passengers are at elevator's floor, load
    while(floors[ev.getFloor()].size()){
        //Grab the person from the floor queue, load them into the car
        ev.loadCar(floors[ev.getFloor()].front());
        //Remove that person from the floor queue
        floors[ev.getFloor()].pop();
    }

    //If elevator has passengers, go to those floors
    if(ev.stillMove()){
        ev.moveFloor();
        return true;
    } else if(checkFloors() != -1){
        //If elevator does not have passengers, but floors have passengers, go pick up passengers
        ev.goToFloor(checkFloors());
        return true;
    }

    //Didn't need to move!
    return false;
}
void Building::generatePassenger(){
    //Call default constructor for a person
    Person newP;

    cout << "Generating Person: " << newP.toString() << ", added to floor " << newP.getSource() << endl;

    //Add that person to the correct floor
    floors[newP.getSource()].push(newP);    
}

int Building::checkFloors(){
    //Iterate over all the floors
    for(int i = 0; i < MAX_FLOOR; i++){
        //If there is a floor that has people, we can stop and return true
        if(!floors[i].empty()){
            return i;
        }
    }
    //Didn't find anyone!
    return -1;
}

void Building::print(){
    cout << "Building Status>> ";

    if(checkFloors()){
        //cout << "People are still waiting! ";
    } else {
        cout << "No people are left. ";
    }

    cout << "Elevator at floor: " << ev.getFloor() << endl;
}

void Building::printStats(){
    ev.printStats();
}