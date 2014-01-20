#include <cstdlib>
#include<stdio.h>
#include<iostream>
using namespace std;

class Node{
public:
	Node * next;
	int data;
};

class Queue{
public:
	Node * head;
	Queue(){
	head=NULL;
	}
    void enqueue(int d);
    int dequeue();
    void displayQueue();
};

void Queue:: enqueue(int d){
Node *n=new Node;
Node *temp;
	if(head==NULL){
		head=n;
		head->data=d;
		head->next=NULL;		
	}
	else{
		temp=head;
		while(temp->next!=NULL){temp=temp->next;}
		temp->next=n;
		temp=temp->next;
		temp->data=d;
		temp->next=NULL;		
	}
}

int Queue:: dequeue(){
Node *temp=head;
int value=0;
	if(temp==NULL){
	cout<<"Queue is Empty"<<endl;
	}
	else{
	value=temp->data;
	head=temp->next;
	delete temp;
	}
	//cout<<"Dequeued item = "<<value<<endl;
	return value;
}

void Queue:: displayQueue(){
Node *temp=head;
	if(temp==NULL){cout<<"Queue is Empty"<<endl;}
	else{
		while(temp!=NULL){
			cout<<temp->data<<"\t";
			temp=temp->next;
		}
	cout<<endl;
	}
}



/*int main(int argc, char** argv) {
    Queue obj;
    int choice=0;
    int value=0;
    while(choice!=4){
        cout<<"1-Enqueue 2-Dequeue 3-Display 4-Exit"<<endl;
        cin>>choice;
        switch(choice){
            case 1:{
             //enqueue
                cout<<"Enter the value to enqueue"<<endl;
                cin>>value;
                obj.enqueue(value);
                break;
            }
            case 2:{
                cout<<"Value dequeued ="<<obj.dequeue()<<endl;
                break;
            }
            case 3:{
                obj.displayQueue();
                break;
            }            
        }
    }
    return 0;
}*/
