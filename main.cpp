#include <iostream>
#include <cstring>
#include "student.h"
#include "node.h"

using namespace std;
void ADD(node* head, student* student); //make new studnet within add function
void PRINT(node* head);
void DELETE(int id, node* head);
float AVERAGE(node* head); 

int main(){
  node* head = new node(NULL, NULL);
  char input[50];
  int id; 
  cout << "student list (again). Commands: print, add, delete, quit, average" << endl;
  while(true){
    cout << "input a command: " << endl;
    cin >> input;
    if(strcmp(input, "print")==0){
      PRINT(head);
    }
    else if(strcmp(input, "add")==0){
      int id;
      int gpa;
      char name[80];
      cout << "id: "<< endl;
      cin >> id;
      cout << "gpa: " << endl;
      cin >> gpa;
      cout << "name: " << endl;
      cin >> name;
      student* stud = new student(name, id, gpa);
      ADD(head, stud);
    }
    else if(strcmp(input, "delete")==0){
      cout << "id of student: " << endl;
      cin >> id;
      DELETE(id, head);
    }
    else if(strcmp(input, "quit")==0){
      return 0;
    }
    else if(strcmp(input, "average")==0){
      cout << AVERAGE(head) << endl;
    }
    else{
      cout << "invalid input! Try again!" << endl;
    }
  }
}
void ADD(node* head, student* student){
  if(head->getStudent() == NULL){
    head->setStudent(student);
  }
  else if(head->getStudent()->id >= student->id){
    node* placeholder = new node(student, head);
  }
  else if(head->getNext ==NULL){
    node* placeholder = new node(student, NULL);
    head->setNext(placeholder);
  }
  else{
    ADD(head->getNext(), student); 
  }
  
}
void PRINT(node* head){

}
void DELETE(int id, node* head){

}
float AVERAGE(node* head){
  return 69;
}

