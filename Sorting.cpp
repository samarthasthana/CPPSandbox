/* 
 * File:   main.cpp
 * Author: Sam
 *
 * Created on January 10, 2014, 2:21 PM
 */

#include <cstdlib>
#include<stdio.h>
#include<iostream.h>
using namespace std;

/*
 * 
 */
void fn_insert(int *A,int i,int j)
{
    int t1,t2;
    t1=A[j];
    A[j]=A[i];
    for(int k=j+1;k<=i;k++)
    {
      t2=A[k];
      A[k]=t1;
      t1=t2;
    }
}

int * fn_merge(int *B1,int l1,int *B2,int l2)
{
    int * R;
    R=new int[l1+l2];
    int i=0,j=0,c=0;
    while (i+j<l1+l2){
        if(i==l1){
            R[c]=B2[j];
            c++;
            j++;
        }
        else{
            if(j==l2){
                R[c]=B1[i];
                c++;
                i++;
            }
            else{
                    if(B1[i]<B2[j]){
                        R[c]=B1[i];
                        i++;
                        c++;
                    }
                    else{
                        R[c]=B2[j];
                        j++;
                        c++;  
                    }
                }
        }        
    }
    return R;
}
int * sort_Merge(int *A,int i,int j)
{
    int *B1,*B2;
    int mid=(j+i)/2;
    if(i==j)
        return &A[j];
    else
    {
     B1=sort_Merge(A,i,mid);
     B2=sort_Merge(A,mid+1,j);
     return fn_merge(B1,mid-i+1,B2,j-mid);
    }
}
int * sort_Insertion(int * A,int len)
{

    cout<<"Using Insertion sort "<<endl;
    
    for(int i=1;i<len;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(A[i]<A[j])
            {
                fn_insert(A,i,j);
            }
        }
    }
    
    return A;
}


/*int main(int argc, char** argv) {


        //int A[20];
    int len=0;
    int *A,*B;
    cout<<"Enter the Length of Array"<<endl;
    cin>>len;
    A=new int[len];
    B=new int[len];
    cout<<"Enter the values of the array"<<endl;
    for(int i=0;i<len;i++)
    {
        cin>>A[i];
    }
    // Insertion sort
    //B=sort_Insertion(A,len);
    B=sort_Merge(A,0,len-1);
    cout<<"Sorted Array is"<<endl;
    for(int i=0;i<len;i++)
    {
        cout<<B[i]<<"\t";
    }
    return 0;
}*/


