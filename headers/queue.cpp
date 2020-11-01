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
// Implementation for queue adaptive container. Based of of stl::queue
//
///////////////////////////////////////////////////////////////////////////////
#include "queue.h"
#include <vector>
#include <list>

template <typename T, class T_storage>
cs273::queue<T, T_storage>::queue()
{ //empty constructor
}

template <typename T, class T_storage>
cs273::queue<T, T_storage>::queue(const queue<T, T_storage> &v)
{ 
    container = v.container;
}

template <typename T, class T_storage>
cs273::queue<T, T_storage>::~queue()
{ //destructor
    container.clear();
}

template <typename T, class T_storage>
void cs273::queue<T, T_storage>::push(const T &element)
{ //add element to container
    container.push_back(element);
}

template <typename T, class T_storage>
T & cs273::queue<T, T_storage>::front()
{ //return value of first element
    return container.front();
}

template <typename T, class T_storage>
T & cs273::queue<T, T_storage>::back()
{ //return value of last element
    return container.back();
}

template <typename T, class T_storage>
void cs273::queue<T, T_storage>::pop()
{ //remove top element from container
    container.pop_front();
}

template <typename T, class T_storage>
int cs273::queue<T, T_storage>::size()
{ //return the number of elements in the container
    return container.size();
}

template <typename T, class T_storage>
bool cs273::queue<T, T_storage>::empty()
{ //return true if container is empty
    return (container.size() == 0);
}

template <typename T, class T_storage>
cs273::queue<T, T_storage> & cs273::queue<T, T_storage>::operator=(const queue<T, T_storage> &v)
{ //overload the = operator
    std::swap(this, v);
}