#include <cstdlib>
#include<stdio.h>
#include<iostream>
using namespace std;

bool checkAnagram(const char * s1, int len1,const char * s2, int len2){
    int arr[256];
    int temp;
    bool value=true;
    for(int i=0;i<256;i++){
        arr[i]=0;
    }
    for(int i=0;i<len1;i++){
        temp=(int)s1[i];
        if(temp>64 || temp < 91){
            temp=temp+32;
        }
        if(temp!=32)arr[temp]++;
    }
    
    for(int j=0;j<len2;j++){
        temp=(int)s2[j];
        if(temp>64 || temp < 91){
            temp=temp+32;
        }
        if(temp!=32)arr[temp]--;
    }
    for(int j=0;j<256;j++){
        if(arr[j]!=0){cout<<j<<"=\t"<<arr[j]<<endl;value=false;}
    }
    return value;
}

/*int main(int argc, char** argv) {
    string s1,s2;
    
    cout<<"Enter first string"<<endl;
    getline(cin,s1);
    cout<<"Enter second string"<<endl;
    getline(cin,s2);
    if(checkAnagram(s1.c_str(),s1.length(),s1.c_str(),s2.length()))cout<<"ANAGRAM"<<endl;
    else cout<<"NOT ANAGRAM"<<endl;
    return 0;
}*/

