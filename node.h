#include <iostream>
#include "student.h"
//header for node class                                                                                  
class node{
public:
  node* getNext();
  void setNext(node* node);
  node(student* inputStudent);
  ~node();
  void setStudent(student *inputStudent);
  student* getStudent();
private:
  student *studentPtr;
  node* next;
};


