#include <cstdlib>
#include<stdio.h>
#include<iostream>
using namespace std;

class Node{
public:
Node *left,*right,*parent;
int data;
};


class Btree{
public:
Node *root;
Btree(){
root=NULL;
}

void inorder(Node* nd);
void postorder(Node* nd);
void preorder(Node* nd);

void add2Tree(Node* nd,Node* p,int d);
void deleteNode(Node* nd,Node* p,int d);
Node * minInTree(Node * nd){return root; }//placeholder , need to write the correct implementation

};

void Btree:: inorder(Node *nd){
if(nd!=NULL){
	inorder(nd->left);
	cout<<nd->data;
	inorder(nd->right);	
}

}
void Btree::preorder(Node * nd){
if(nd!=NULL){
	preorder(nd->left);
	preorder(nd->right);
	cout<<nd->data;
}
}
void Btree::postorder(Node * nd){
if(nd!=NULL){
	cout<<nd->data;
	postorder(nd->left);
	postorder(nd->right);	
}
}

void Btree::add2Tree(Node *nd,Node * p,int d){
Node *n=new Node;
if(nd==NULL){
	if(root==NULL){
	root=n;}
	nd=n;
	nd->left=NULL;
	nd->right=NULL;
	nd->data=d;
	nd->parent=p;
}
else{
	if(d>nd->data){
		add2Tree(nd->right,p,d);
	}
	else if(d<= nd->data){
		add2Tree(nd->left,p,d);
	}
}

}

void Btree::deleteNode(Node * nd,Node *p,int d){
Node *temp=NULL;
if(nd!=NULL){
	if(d==nd->data){
		if(nd->left==NULL && nd->right==NULL){
			// del this node as it is the leaf
			if(p->left==nd){p->left=NULL;}
			else{p->right=NULL;}
			delete nd;
		}
		else{
			//If one of the sub tress exist
			if(nd->left==NULL && nd->right!=NULL){
					if(p->left==nd){p->left=nd->right;}
					else{p->right=nd->right;}
					delete nd;
			}
			else{
				if(nd->left!=NULL && nd->right==NULL){
					if(p->left==nd){p->left=nd->left;}
					else{p->right=nd->left;}
					delete nd;
					}
				// if both the sub trees exist
				else{
					temp=minInTree(nd->right);
					temp->parent->left=NULL;
					temp->parent=p;
					if(p->left==nd){p->left=temp;}
					else{p->right=temp;}
					temp->right=nd->right;
					delete nd;
				}
			}
		}
	}

}

}




/*int main(int argc, char** argv) {
    return 0;
}*/
