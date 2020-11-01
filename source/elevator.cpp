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
// Implementation for Elevator object used in queue application
//
///////////////////////////////////////////////////////////////////////////////

#include "elevator.h"
#include <iostream>

using std::cout;
using std::endl;

Elevator::Elevator(){
    curFloor =0;
    curTime =0;
    totalDeliveries = 0;
    totalRideTime = 0;
}

void Elevator::loadCar(const Person& p){
    //Push Person into the Car
    car.push(p);
    //Set their curTime to the current time of elevator
    car.back().setStartTime(curTime);
    cout << endl << "**** Loaded: " << car.back().toString() << " at floor " << curFloor << endl << endl;
}

bool Elevator::moveFloor(){
    //Check to see if there is anyone to move
    if(!stillMove()){
        cout << "Car is done!" << endl;
        return false;
    } else {
        //Move to the first person's floor
        int dest = car.front().getDestination();
        if(dest == curFloor){
            //Got to the correct floor!
            car.front().setEndTime(curTime);            
            cout << endl <<  "#### Removing: " << car.front().toString(curTime) << endl << endl;

            //Update stats
            totalDeliveries++;
            totalRideTime += car.front().getElapsedTime();

            //Actually remove the person
            car.pop();
        } else if (dest > curFloor){
            //Need to keep going up!
            curFloor++;
        } else {
            //Need to go down!
            curFloor--;
        }
        //Incrament time regardless of action
        curTime++;
        return true;
    }
}

bool Elevator::stillMove(){
    return !car.empty();
}

string Elevator::toString(){
    return "Elevator is currently at floor " + std::to_string(curFloor) +
           " with " + std::to_string(car.size()) + " people";

}

void Elevator::goToFloor(int f){
    cout << "Jumping to floor " << f << endl;
    if(f > curFloor){
        //Need to go Up
        curTime += (f - curFloor);
        curFloor = f;
    } else {
        //Need to go down
        curTime += (curFloor - f);
        curFloor = f;
    }
}

 int Elevator::getFloor() const{
     return curFloor;
 }

 void Elevator::printStats(){
     cout << endl << "Elevator Stats: " << endl;
     cout << "Total Number of deliveries: " << totalDeliveries << endl;
     cout << "Average ride time: " << static_cast<double> (totalRideTime) / static_cast<double> (totalDeliveries) << " floors" << endl;
 }