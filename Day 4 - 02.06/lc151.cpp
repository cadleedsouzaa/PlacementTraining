#include <bits/stdc++.h>
using namespace std;

int main(){
    string s="the sky is blue                  hi f u        ";
    stringstream ss(s);
    string word;
    string res;
    while(ss >> word){
        res=word+" "+res;
    }
    
    cout <<  res;
}