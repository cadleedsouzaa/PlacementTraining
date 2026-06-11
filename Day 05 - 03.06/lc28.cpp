#include<bits/stdc++.h>
using namespace std;

int main(){
    string haystack="sasatbutsad";
    string needle="sad";
    
    int haysize=haystack.size();
    int needsize=needle.size();
    int j;

    for (int i=0;i<haysize-needsize;i++){
        for( j=0;j<needsize;j++){
            if(haystack[j+i]!=needle[j]){
                break;
            }
        }
        if(j==needsize){
            cout<< i;
        }
    }
   
    
    cout << -1;
    return 0;}


