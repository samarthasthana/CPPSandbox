#include <cstdlib>
#include<stdio.h>
#include<iostream>
using namespace std;

class HashMap{
private:
    int hash[10000];
public:
    bool inHash(int i);
    void rem4mHash(int i);
    void add2Hash(int i);
    int findDiffPairs(int * p, int len,int diff);
};

void HashMap::add2Hash(int i){
    if(i<10000 && i>=0){
        if(hash[i]==0){
            hash[i]++;
        }
    }
}

bool HashMap::inHash(int i){
     if(i<10000 && i>=0){
        if(hash[i]==1){
            return true;
        }
    }
     return false;
}

void HashMap::rem4mHash(int i){
     if(i<10000 && i>=0){
            hash[i]==0;
    }
}

int HashMap::findDiffPairs(int* p, int len, int diff){
    int i=0,pairs=0;
    while(i<len){
        add2Hash(p[i]);
        i++;
    }
    i=0;
    while(i<len){
        if(inHash(p[i])){
            if(inHash(p[i]+diff)){
                pairs++;
                rem4mHash(p[i]);
            }
        }
        i++;
    }
    
    return pairs;
}

int main(int argc, char** argv) {

    HashMap obj;
    int len=0,i=0,diff=0;;
    cout<<"Enter the number of elements in the array"<<endl;
    cin>>len;
    int *p=new int[len];
    cout<<"Enter the elements in the array"<<endl;
    while(i<len){
        cin>>p[i];
        i++;
    }
    cout<<"Enter the value of difference"<<endl;
    cin>>diff;
    cout<<"The number of pairs found = "<<obj.findDiffPairs(p,len,diff);
    
    return 0;
}
