#include <cstdlib>
#include<stdio.h>
#include<iostream>
using namespace std;

int maximumOf(int i,int j){
    if(i>j)return i;
    else return j;    
}

void maxSubArray(int arr[],int len){
    int i=0,m_here=arr[0],m_far=arr[0];
    int ind_start=0,ind_temp=0,ind_end=0;
    for(i=1;i<len;i++){
        if(m_here<0){
            m_here=arr[i];
            ind_temp=i;
        }
        else{
            m_here+=arr[i];            
        }
        if(m_here>m_far){
            m_far=m_here;
            ind_start=ind_temp;
            ind_end=i;
        }        
    }
    cout<<"The final sum= "<<m_far<<"\t start index= "<<ind_start<<"\t end index= "<<ind_end<<endl;
}

/*int main(int argc, char** argv) {
    
    int len;
    cout<<"Enter the length of the array"<<endl;
    cin>>len;
    int * arr=new int[len];
    cout<<"Enter the values of the array"<<endl;
    for(int i=0;i<len;i++){
        cin>>arr[i];
    }
    maxSubArray(arr,len);
}*/
