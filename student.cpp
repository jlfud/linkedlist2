#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

student::student(const char* newname, int newid, float newgpa){
  strcpy(name, newname);
  id = newid;
  gpa = newgpa;
}
student::~student(){
  //destructor
  delete name; 
}
