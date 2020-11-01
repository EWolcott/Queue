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
// Header for Elevator object used in queue application
//
///////////////////////////////////////////////////////////////////////////////

#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "person.h"
#include "queue.h"

#include <string>

// MODIFY BELOW vvvvvvvv

#include <queue>
using cs273::queue;

#include <list>
using std::list;

//This defines container to be the specified (std::list<Person>) container
typedef std::list<Person> e_container;

// MODIFY ABOVE ^^^^^^^

class Elevator{

    private:
        int curFloor; //Current position of the elevator
        //              Should always be between source and destinations of Persons
        queue<Person, e_container> car; // Current occupants of the Elevator

        //Timing metrics
        // Time is measured in floors traveled
        int curTime;         // Time at present moment
        int totalDeliveries; // Running total of number of people delivered
        int totalRideTime;   // RUnning total of trip times of each passenger

    public:
        Elevator();

        //Basic getter
        int getFloor() const;

        // Add person to the car
        // p - person to be added
        // Records the time the person go on the car
        // Adds them to the queue on the car
        void loadCar(const Person& p);

        // Motion method of elevator
        // Elevator will move towards the destination floor of the first person in the car
        // Returns true if there are still more actions to be done
        // Returns false if there are no more things to do (and hence, does not move)
        // Running this takes one 'floor' as a simulation time
        // Handles the removing of passengers at their floor
        bool moveFloor();

        // Returns true if there is more to process
        // false otherwise
        bool stillMove();

        // Quick movement to skip floors
        // Aids in speeding up the simulation
        // This still increases running time proportianate to number of floors
        void goToFloor(int f);

        //Printing Methods
        string toString();
        void printStats();
};

#endif