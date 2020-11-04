#include <iostream>
#include <cstring>
#include "student.h"
#include "node.h"
#include <iomanip>

using namespace std;
void ADD(node* head, student* student); //function prototypes
void PRINT(node* head);
void DELETE(int id, node* &h, node* head);
float AVERAGE(node* head, float total, int count); 

int main(){
  node* head = new node(NULL);
  head->setNext(NULL);  //initiate head
  char input[50];
  int id;  //for user input
  cout << "student list (again). Commands: print, add, delete, quit, average" << endl;
  while(true){ //keep on gettint input until "quit" is entered
    //otherwise, perform the corresponding functions or tell the user
    //that they inputted incorrectly
    cout << "input a command: " << endl;
    cin >> input;
    if(strcmp(input, "print")==0){
      PRINT(head); //print students
    }
    else if(strcmp(input, "add")==0){
      int id;
      float gpa;
      char name[80];
      cout << "id: "<< endl;
      cin >> id;
      cout << "gpa: " << endl;
      cin >> gpa;
      cout << "name: " << endl;
      cin >> name; //get student info, make student, add function
      student* stud = new student(name, id, gpa);
      ADD(head, stud);
    }
    else if(strcmp(input, "delete")==0){
      cout << "id of student: " << endl;
      cin >> id;
      DELETE(id, head, head); //delete student by id
    }
    else if(strcmp(input, "quit")==0){
      return 0; //quit
    } 
    else if(strcmp(input, "average")==0){
      cout << fixed << setprecision(2) << AVERAGE(head, 0, 0) << endl;
      //average after adjusting precision
    }
    else{
      cout << "invalid input! Try again!" << endl;
    }
  }
}
void ADD(node* head, student* student){ //head represents current node
  if(head->getStudent() == NULL){
    head->setStudent(student); //if there is no student in the head, we
    //add the student there
  }
  else if(head->getStudent()->id >= student->id){
    //if the head student's id is after the new student, we put the student
    //before the head, and make the new head placeholder
    node* placeholder = new node(head->getStudent());
    placeholder->setNext(head->getNext());
    head->setNext(placeholder);
    head->setStudent(student);
  }
  else if(head->getNext() == NULL){
    //if we have reached the end of the list, we just put it at the end
    node* placeholder = new node(student);
    placeholder->setNext(NULL);
    head->setNext(placeholder);
  }
  else{
    //if we have not satisfied any of the above, we add with the next node
    ADD(head->getNext(), student); 
  }
  
}
void PRINT(node* head){
  //while we still have nodes, pritn recursively
  if(head != NULL){
    if(head->getStudent() != NULL){
      cout << head->getStudent()->id << " " << head->getStudent()->name << " " << fixed << setprecision(2) << head->getStudent()->gpa << endl;
      PRINT(head->getNext());
    }
  }
}
void DELETE(int id, node* &h, node* head){
  char input[10];
  if(head->getNext() == NULL){
    if(head->getStudent() != NULL){
      if(head->getStudent()->id == id){
	//if head is the only node, delete that
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
    //at any given point if we see a student with the right id
    if(head->getNext()->getStudent()->id == id){
      cout << "would you like to delete " << head->getNext()->getStudent()->name << "?" << endl;
      cin >> input;
      if(strcmp(input, "yes")==0){
	cout << "student deleted." << endl;
	//set the previous to the one after, then delete
	node* placeHolder = head->getNext()->getNext();
	head->getNext()->~node();
	head->setNext(placeHolder);
      }
    }
    else if(head->getStudent()->id == id){ 
      //if it is the head node with nodes after it
      cout << "would you like to delete " << head->getStudent()->name << "?" << endl;
      cin >> input;
      if(strcmp(input, "yes")==0){
        cout << "student deleted." << endl;
	node* temp = head; 
	h = h->getNext();
	temp->~node();
      }
    }
    else{
      DELETE(id, h, head->getNext());
    }
  }
}
float AVERAGE(node* head, float total, int count){ 
  //recursively get total until we reach end
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
