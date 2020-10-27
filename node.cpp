#include <iostream>
#include <cstring>
#include "student.h"
#include "node.h"

using namespace std;

node::node(student* newstudent, node* newnode){
  stud = newstudent;
  linkNode = newnode;
}
node::~node(){
  delete stud;
  linkNode = NULL;
}
node* node::getNext(){
  return linkNode;
}
void node::setNext(node* newnode){
  linkNode = newnode; 
}
student* node::getStudent(){
  return stud;
}
void node::setStudent(student* newstudent){
  stud = newstudent; 
}
