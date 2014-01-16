/* 
 * File:   main.cpp
 * Author: Sam
 *
 * Created on January 16, 2014, 12:46 PM
 */
#include<stdio.h>
#include<iostream.h>
#include <cstdlib>
#include <string>

using namespace std;

/*
 * 
 */
class HashMap{
private:
    int arr[500];
public:
    HashMap(){// default constructor
        for(int i=0;i<500;i++){
            arr[i]=0;
        }
    }
    int getKey(char c){
        return (int)c;
    }
    int atKey(int z){
        arr[z]++;
        return arr[z];        
    }
};

bool checkUnique(const char *str, int len, HashMap obj){
    if(len>256){
        return false;
    }
    for(int j=0;j<len;j++){
        if(obj.atKey(obj.getKey(str[j]))>1){
            return false;
        }
    }
    return true;
}
/*int main(int argc, char** argv) {

    string str;
    HashMap obj;
    cout<<"Enter the String to check for unique characters"<<endl;
    getline(cin,str);
    //cout<<obj.getKey('a')<<endl;
    if(checkUnique(str.c_str(),str.length(),obj)){
        cout<<"String unique"<<endl;
    }else
    {
        cout<<"String not unique"<<endl;
    }
    return 0;
}*/


