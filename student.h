#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

using namespace std;

class student{
public:
  student(const char*, int, float);
  ~student();
  char* name = new char[80];
  int id;
  float gpa;
};

#endif
