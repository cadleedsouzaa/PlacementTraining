#include <bits/stdc++.h>
using namespace std;

int main(){
    string s="Hello World yayyyyyy    ok  ";
    stringstream ss(s);
    string word;
    int ans=0;
    while(ss>>word){
         ans=word.size();
    }
    cout <<  ans;
}