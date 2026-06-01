//given an integer array nums sorted in ascending order , remove the duplicates in place such that each unique element 
//appears only once
// the relative order of the elements should be kept same 

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v={1,2,2,3,3,4,4,4,5,5,9,10};
    int idx=1;
    int og_size=v.size();
    for (int i=1;i<og_size;i++){
        if(v[i]!=v[i-1]){
            v[idx++]=v[i];
        }
        else{
            v.push_back(v[i]);
            i++;
        }
    }
    for (int x:v){
        cout << x << " ";
    }









    }