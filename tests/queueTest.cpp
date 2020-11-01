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
// Unit Test for queue implimentation
//
///////////////////////////////////////////////////////////////////////////////

#include "gtest/gtest.h"
#include "queue.h"
#include <string>

using namespace cs273;

TEST(queue, copy)
{
  cs273::queue<std::string> sandwich;
  std::string t = "hello!";
  sandwich.push(t);
  t = "Well this is awkward";
  sandwich.push(t);
  t = "jelly";
  sandwich.push(t);
  sandwich.pop();
  sandwich.pop();
  cs273::queue<std::string> sandwich2(sandwich);

  EXPECT_EQ(sandwich2.front(), "jelly");
}


TEST(queue, push)
{
  cs273::queue<std::string> sandwich;
  std::string t = "hello!";
  sandwich.push(t);
  EXPECT_EQ(sandwich.front(), "hello!");
}

TEST(queue, pop)
{
  cs273::queue<std::string> sandwich;
  std::string t = "hello!";
  sandwich.push(t);
  t = "Well this is awkward";
  sandwich.push(t);
  t = "jelly";
  sandwich.push(t);
  sandwich.pop();
  sandwich.pop();
  EXPECT_EQ(sandwich.front(), "jelly");
}

TEST(queue, front)
{
  cs273::queue<std::string> sandwich;
  std::string t = "hello!";
  sandwich.push(t);
  t = "Well this is awkward";
  sandwich.push(t);
  t = "jelly";
  sandwich.push(t);
  sandwich.pop();
  EXPECT_EQ(sandwich.front(), "Well this is awkward");
}

TEST(queue, back)
{
  cs273::queue<std::string> sandwich;
  std::string t = "hello!";
  sandwich.push(t);
  t = "Well this is awkward";
  sandwich.push(t);
  t = "jelly";
  sandwich.push(t);
  sandwich.pop();
  EXPECT_EQ(sandwich.back(), "jelly");
}

TEST(queue, empty)
{
  cs273::queue<std::string> sandwich;
  EXPECT_EQ(sandwich.empty(), true);
}

TEST(queue, size)
{
  cs273::queue<std::string> sandwich;
  std::string t = "hello!";
  sandwich.push(t);
  t = "Well this is awkward";
  sandwich.push(t);
  t = "jelly";
  sandwich.push(t);
  EXPECT_EQ(sandwich.size(), 3);
}

TEST(queue, template)
{
  cs273::queue<int> intsandwich;
  int t = 1;
  intsandwich.push(t);
  t = 2;
  intsandwich.push(t);
  t = 3;
  intsandwich.push(t);
  intsandwich.pop();
  EXPECT_EQ(intsandwich.front(), 2);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}