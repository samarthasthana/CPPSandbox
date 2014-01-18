#include <cstdlib>
#include<stdio.h>
#include<iostream>
using namespace std;

void reverseStr(string str){
    
    int len=0;
    char temp;
    len=str.length();
    int i=0,j=0;
    j=len-1;
    while(i<=j){
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
   cout<<"Reversed string= "<<str;
   
}

/*int main(int argc, char** argv) {
  
    string str;
    cout<<"Enter the string to reverse"<<endl;
    getline(cin,str);
    reverseStr(str);
    return 0;
}*/

