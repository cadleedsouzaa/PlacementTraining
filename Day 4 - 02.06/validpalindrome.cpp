#include <bits/stdc++.h>
using namespace std;

int main(){
    string s="delston";
    
    
    int n=s.size();
    int l=0;
    int r=n-1;
    bool ok=true;
    string res;
    while(l<r){
        while(l<r && !isalnum(s[l])){
            l++;
        }
        while(l<r && !isalnum(s[r])){
            r--;
        }
        if(tolower(s[l])!=tolower(s[r])){
            ok= false;
            break;
        }
        l++;
            r--;
    }
    if(ok){
        cout<< "Palindrome";
    }
    else{
        cout <<"not valid palindrome";

    }
    
    return 0;
}