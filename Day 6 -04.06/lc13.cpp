#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<char,int> mp;
    string s="XC";
    
    mp['I']=1;
    mp['V']=5;
    mp['X']=10;
    mp['L']=50;
    mp['C']=100;
    mp['D']=500;
    mp['M']=1000;
    

    int ans=0;
    int n=s.size();
    for (int i=0;i<n-1;i++){
        if(mp[s[i]]<mp[s[i+1]]){
            ans-=mp[s[i]];
        }
        else{
            ans+=mp[s[i]];
        }
    }
    cout << ans+mp[s[n-1]];

}