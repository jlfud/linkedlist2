#include <iostream>
#include <cstring>
#include "student.h"
#include "node.h"

using namespace std;
void ADD(node* head, student* student); //make new studnet within add function
void PRINT(node* head);
void DELETE(int id, node* head);
float AVERAGE(node* head, float total, int count); 

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
      cout << AVERAGE(head, 0, 0) << endl;
    }
    else{
      cout << "invalid input! Try again!" << endl;
    }
  }
}
void ADD(node* head, student* student){ //head represents current node
  if(head->getStudent() == NULL){
    head->setStudent(student);
  }
  else if(head->getStudent()->id >= student->id){
    node* placeholder = new node(head->getStudent(), head->getNext());
    head->setNext(placeholder);
    head->setStudent(student);
  }
  else if(head->getNext() == NULL){
    node* placeholder = new node(student, NULL);
    head->setNext(placeholder);

  }
  else{
    ADD(head->getNext(), student); 
  }
  
}
void PRINT(node* head){
  if(head != NULL){
    if(head->getStudent() != NULL){
      cout << head->getStudent()->id << " " << head->getStudent()->name << " " << head->getStudent()->gpa << endl;
      PRINT(head->getNext());
    }
  }
}
void DELETE(int id, node* head){
  char input[10];
  if(head->getNext() == NULL){
    if(head->getStudent() != NULL){
      if(head->getStudent()->id == id){
	cout << "would you like to delete " << head->getStudent()->name << "?" << endl;
	cin >> input;
	if(strcmp(input, "yes")==0){
	  cout << "student deleted." << endl;
	  delete head->getStudent();
	  head->setStudent(NULL); 
	}
      }
      else{
	cout << "id not found" << endl;
      }
    }
    else{
      cout << "id not found" << endl;
    }
  }
  else{
    if(head->getNext()->getStudent()->id == id){
      cout << "would you like to delete " << head->getNext()->getStudent()->name << "?" << endl;
      cin >> input;
      if(strcmp(input, "yes")==0){
	cout << "student deleted." << endl;
	node* placeHolder = head->getNext()->getNext();
	head->getNext()->~node();
	head->setNext(placeHolder);
      }
    }
    else if(head->getStudent()->id == id){ //if it is the head node
      cout << "would you like to delete " << head->getStudent()->name << "?" << endl;
      cin >> input;
      if(strcmp(input, "yes")==0){
        cout << "student deleted." << endl;
        delete head->getStudent();
	node* temp = head->getNext();
	head->setStudent(temp->getStudent());
	head->setNext(temp->getNext());
      }
    }
    else{
      DELETE(id, head->getNext());
    }
  }
}
float AVERAGE(node* head, float total, int count){ 
  if(head != NULL){
    if(head->getStudent()==NULL){
      return (total/count);
    }
    total += head->getStudent()->gpa;
    count++;
    return AVERAGE(head->getNext(), total, count); 
  }
  else{
    return (total/count); 
  }
}

