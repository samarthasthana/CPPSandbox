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

class MyList{
private:
    Node *head; 
    int length;
public:
    MyList(){
        head=NULL;
        length=0;
    }
    void append2(int data);
    void delete4m(int data);
    void incLength(){length++;}
    void decLength(){length--;}
    void getLength(){cout<<"Length is ="<<length<<endl;}
    void displayList();    
};


void MyList:: displayList(){
    Node *temp=head;
    if(temp==NULL){
        cout<<"The List is Empty"<<endl;
    }
    else{
        cout<<"\nThe List =\t";
        while(temp!=NULL){
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
        cout<<endl;
    }
}

void MyList::append2(int d){
    Node *n=new Node;
    Node *temp=head;
    if(head==NULL){
        head=n;
        head->data=d;
        head->next=NULL;
        incLength();
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
        temp->next->data=d;
        temp->next->next=NULL;
        incLength();
    }
}

void MyList::delete4m(int d){
    Node *temp=head,*temp2=NULL;
    if(head->data==d){
        //delete the head        
        head=temp->next;
        delete(temp);
        decLength();
    }
    else{
        // delete from other places 
        while(temp->next!=NULL){
            if(temp->next->data==d){
                //need to delete this node
                temp2=temp;
                temp->next=temp->next->next;
                delete temp2;
                decLength();
                break;
            }
            temp=temp->next;
        }
    }
}

/*int main(int argc, char** argv) {
    int choice =0;
    MyList obj;
    int data;
    while (choice!=10){
        cout<<"Enter 1) Append to list 2) Delete from list 3) Length Of List 4) Display the list 10) Exit"<<endl;
        cin>>choice;
        switch(choice){
                case 1:
                {
                    cout<<"Enter the data to append"<<endl;
                    cin>>data;
                    obj.append2(data);
                    break;
                }
                case 2:
                {
                    cout<<"Enter the data to delete"<<endl;
                    cin>>data;
                    obj.delete4m(data);
                    break;
                }
                case 3:
                {
                    obj.getLength();
                    break;
                }
                case 4:
                {
                    obj.displayList();
                    break;
                }
        }
    }
    
    return 0;
}*/
