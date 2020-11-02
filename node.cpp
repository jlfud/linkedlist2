#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

//get next node                                                                                          
node* node::getNext(){
  return next;

}

//set next node                                                                                          
void node::setNext(node* node){
  next = node;

}

void node::setStudent(student *inputStudent){
  studentPtr = inputStudent;

}

student* node::getStudent(){
  return studentPtr;
}


//constructor                                                                                            
node::node(student* inputStudent){
  studentPtr = inputStudent;

}

//destructor                                                                                             
node::~node(){
  delete studentPtr;
}
