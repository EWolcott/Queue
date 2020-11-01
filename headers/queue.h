///////////////////////////////////////////////////////////////////////////////
// Group: <ID>
// Names: Ethan Wolcott
// Date: 6/16/2020
// Course Code: CS-273-<X>
//
// License: CS172 students at whitworth may edit this file but not share this 
// file electronically with other students.
//
// Copyright (C) Ethan Wolcott 2020 - 2021
// Derived from work by Scott Griffith
//
// Resources used: <Enter and external citations needed>
// Collaborators: <If you worked with others place their name here> 
//
// Header for queue adaptive container. Based of of stl::queue
//
///////////////////////////////////////////////////////////////////////////////

#ifndef QUEUE_H
#define QUEUE_H
#include <vector>
#include <list>

namespace cs273
{

    //template class allows for broader use
    template <typename T, class T_storage=std::list<T>> //this heading allows for a list to be stored as the container.
    class queue //simply switch out the std::list for vector or deque if so desired.
    {

    private:
        //create a container.
        T_storage container;


    public:
        queue();                                //empty constructor
        queue(const queue<T, T_storage> &v);                                //copy consrtuctor
        ~queue();                               //destructor
        queue<T, T_storage> &operator=(const queue<T, T_storage> &v); //overloaded = operator for comparing stacks
        int size();                             //return the size of elements in the container
        void push(const T &element);            //add an element to the container
        void pop();                             //remove top element from the container
        T& front();
        T& back();                               //return the top element of the container
        bool empty();                           //return true if container is empty
    };
} // namespace cs273

#include "queue.cpp"

#endif