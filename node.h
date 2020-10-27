#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

class node{
public:
  node(student*, node*); //includes student and next node in constructor
  ~node(); //destructor
  node* getNext(); //getters and setters
  void setNext(node*);
  student* getStudent();
  void setStudent(student*);
private:
  student* stud;
  node* linkNode; 
};

#endif
