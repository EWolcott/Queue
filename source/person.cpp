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
// Implementation for Person object used in queue application
//
///////////////////////////////////////////////////////////////////////////////

#include "person.h"
#include "building.h" //Needed for MAX_FLOOR

int Person::idPool = 0;

Person::Person() {
    sourceFloor = (rand() % Building::MAX_FLOOR)+1;
    destFloor = (rand() % Building::MAX_FLOOR)+1;
    initialSetUp();
}

Person::Person(int sF) {
    sourceFloor = sF;
    destFloor = (rand() % Building::MAX_FLOOR)+1;
    initialSetUp();
}

Person::Person(int sF, int dF) {
    sourceFloor = sF;
    destFloor = dF;
    initialSetUp();
}

void Person::setStartTime(int i){
    startTime = i;
}
void Person::setEndTime(int i){
    endTime = i;
}
int Person::getElapsedTime(){
    return endTime - startTime;
}

int Person::getID(){
    return id;
}
int Person::getDestination(){
    return destFloor;
}
int Person::getSource(){
    return sourceFloor;
}

string Person::toString() const{
    return "Person (" +  std::to_string(id) + ") \ts:" +
           std::to_string(sourceFloor) + " d:" + std::to_string(destFloor) +
           " \t initial floor count: " + std::to_string(startTime);
}

string Person::toString(int curTime) const{
    return "Person (" +  std::to_string(id) + ") \ts:" +
           std::to_string(sourceFloor) + " d:" + std::to_string(destFloor) +
           " \t elapsed / initial floor count: " + std::to_string(curTime - startTime) + "/" + std::to_string(startTime);
}

void Person::setIDPool(int n){
    idPool = n;
}
