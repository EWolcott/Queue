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
// Building header for queue application
//
///////////////////////////////////////////////////////////////////////////////

#ifndef BUILDING_H
#define BUILDING_H

#include "person.h"
#include "elevator.h"
#include "queue.h"

// MODIFY BELOW vvvvvvvv

#include <queue>
using cs273::queue;

#include <vector>
using std::vector;

//This defines container to be the specified (std::list<Person>) container
typedef std::deque<Person> b_container;

// MODIFY ABOVE ^^^^^^^

class Building{
    private:
        Elevator ev; // Elevator
        vector< queue<Person, b_container> > floors; // Line of people at each floor, index == floor number

        // Utility, checks to see if there is still a floor with a waiting passenger
        // Returns back the number of the floor with at least one waiting Person
        int checkFloors();

    public:
        static const int MAX_FLOOR = 15; // Total height of the building

        Building();

        // Check to see if there are any people waiting for the elevator at its current location
        // If there are, moves them into the elevator
        // If there are not, elevator moves on
        bool processElevator();

        // Add a new person to a floor queue
        // This takes advantage of the person constructor to randomize
        void generatePassenger();

        // Informational Print Outs
        void print();
        void printStats();
};

#endif