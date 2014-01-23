#include <cstdlib>
#include<stdio.h>
#include<iostream>
using namespace std;

class Node{
public:
Node *next;
int data;
Node(){
next=NULL;
data=0;
}
};

class Queue{
    
public:
Node *head,*tail;
int maxSize;
int actSize;
void enq(int d);
int deq();
void display();
Queue(int s);

};

Queue::Queue(int s){
head=NULL;
tail=NULL;
maxSize=s;
actSize=0;    
}

void Queue:: display(){
    Node *temp=head;
    if(head==NULL){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        while(temp!=NULL){
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
    }//else
    cout<<endl;
}


int Queue::deq(){
Node *temp=head;
int value=0;
if(head==NULL){
cout<<"Empty Queue"<<endl;
}
else{
value=head->data;
head=temp->next;
delete temp;
actSize--;
}
return value;
}//eof


void Queue::enq(int d){
Node *n=new Node;
if(head==NULL && maxSize>0){
head=n;
head->data=d;
head->next=NULL;
tail=n;
actSize++;
}
else{
if(actSize==maxSize){
deq();
}
tail->next=n;
tail=n;
tail->data=d;
actSize++;
tail->next=NULL;
}//else
}//eof


int main(int argc, char** argv) {
int size,data;
cout<<"Enter the Max size for the linked list"<<endl;
cin>>size;
Queue q1(size);
int choice=0;
while(choice!=4){
    cout<<"1-Enqueue 2-Dequeue 3-Display 4-Exit"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
        {
            cout<<"Enter Data:"<<endl;
            cin>>data;
            q1.enq(data);
            break;
        }//case
        case 2:
        {
            cout<<"Dequeued value ="<<q1.deq()<<endl;;
            break;
        }
        case 3:
        {
           q1.display(); 
           break;
        }
    }//swtich
    
}//while
}
