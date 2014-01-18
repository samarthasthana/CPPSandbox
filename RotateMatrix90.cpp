#include <cstdlib>
#include<stdio.h>
#include<iostream>
using namespace std;

void swapEm(int ** arr,int i1,int j1,int i2,int j2){
    int temp =0;
    temp=arr[i1][j1];
    arr[i1][j1]=arr[i2][j2];
    arr[i2][j2]=temp;    
}

void rotateMatrix(int ** arr,int n){
    int i=0,j=0;
    while(i<n){
        j=i;
        while(j<n){
            swapEm(arr,i,j,j,i);
            j++;
        }
        i++;
    }
    i=0;j=0;
    while(i<n){
        while(j<n){
            swapEm(arr,i,j,n-1-i,j);
            j++;
        }
        i++;
    }
}



void displayMatrix(int ** arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n; j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    
}


void inputMatrix(int ** arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n; j++){
            cin>>arr[i][j];
        }        
    }
    
}

/*int main(int argc, char** argv) {

    int n;
    cout<<"Enter the dimensions for n*n matrix"<<endl;
    cin>>n;
    cout<<"Enter the Matric elements"<<endl;    
    int **arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
    }
    inputMatrix(arr,n);
    cout<<"entered Matrix is " <<endl;
    displayMatrix(arr,n);
    rotateMatrix(arr,n);
    cout<<"rotated Matrix is "<<endl;
    displayMatrix(arr,n);
    return 0;
}*/

