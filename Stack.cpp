#include <cstdlib>
#include<stdio.h>
#include<iostream>
using namespace std;

class Node{
public:
	Node *next;
	int data;
};

class Stack{
public:
	Node *head;
	Stack(){head=NULL;}
	Node * Head(){return head;}
	int pop();
	void push(int d);
	void displayStack(){
	Node *temp;
		if(head==NULL){
			cout<<"The Stack is empty"<<endl;
		}
		else{
			temp=head;
			while(temp!=NULL){
			cout<<temp->data<<"\t";
			temp=temp->next;
			}
		}
		cout<<endl;
	}
};


int Stack:: pop(){
// remove the last value in the stack
int value=0;
Node *temp=head;
Node * temp2;
	if(temp==NULL){ // when stack is empty
		cout<<"The Stack is empty"<<endl;
	}
	else{
	if(temp->next==NULL){ // popping the head
	value=temp->data;
	head=NULL;
	delete temp;
	}
	else{
	while(temp->next->next!=NULL){
	temp=temp->next;
	}
	value=temp->next->data;
	temp2=temp->next;
	temp->next=NULL;
	delete temp2;
	}
	}
	return value;
}


void Stack:: push(int d){
	Node *n=new Node;
	Node *temp;
	if(head==NULL){ // pushing to the head
		head=n;
		head->data=d;
		head->next=NULL;
	}
	else{ // pushing everywhere else
		temp=head;
		while(temp->next!=NULL){temp=temp->next;}
		temp->next=n;
		temp=temp->next;
		temp->data=d;
		temp->next=NULL;
	}
}




/*int main(int argc, char** argv) {
    Stack obj;
    int choice=0,value=0;
    while(choice !=4){
        cout<<"1-POP 2-PUSH 3-DISPLAY 4-EXIT"<<endl;
        cin>>choice;
        switch(choice){
            case 1:{
                value=obj.pop();
                cout<<"Popped value="<<value<<endl;
                break;
            }
            case 2:{
                cout<<"Enter the value to push"<<endl;
                cin>>value;
                obj.push(value);
                break;       
            }
            case 3:{
                cout<<"Stack contains:"<<endl;
                obj.displayStack();
                break;
            }            
                    
        }
              
    }
    
    return 0;
}*/
