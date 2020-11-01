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
// Header for Person object used in queue application
//
///////////////////////////////////////////////////////////////////////////////

#ifndef PERSON_H
#define PERSON_H

#include <string>
using std::string;

class Person{
    private:
        int destFloor;   // Person's Desired Floor
        int sourceFloor; // Person's Starting Floor
        int id;          // Unique id for each person
        int startTime;   // Elevator 'time' that the person first started interaction with the elevator
        int endTime;     // Last time the person interacted with the elevator 

        //Static Constructor Variables
        static int idPool;

        // Utility, sets id, start/endTime to their respective values
        // Called from each of the constructors
        void initialSetUp(){
            id = idPool++;
            startTime = 0;
            endTime = 0;
        };

    public:
        // Simple Constructors
        // Each one calls initalSetUp
        //      sets unique ID, and zeroes startTime and endTime
        // sF - starting floor
        // dF - destination floor
        //      floors are set randomly if not defined
        Person();
        Person(int sF);
        Person(int sF, int dF);

        //Basic Setters / Getters
        void setStartTime(int i);
        void setEndTime(int i);        
        int getID();
        int getDestination();
        int getSource();

        // Calculates the total time the passeget waited, primarily on the elevator
        // returns startTime - endTime
        int getElapsedTime();

        //Converts string object into a string for easy printing
        string toString() const;
        // curTime allows for an elapsed tome time to be displayed
        string toString(int curTime) const;

        // Utility to initilize the ID pool for Persons
        // Should be called before any person's are made.
        // n - initial value of id, all IDs will increment off of this value
        static void setIDPool(int n);
};

#endif