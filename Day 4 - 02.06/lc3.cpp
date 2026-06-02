#include <bits/stdc++.h>
using namespace std;

int main(){
    string s="ababcbaabcdeb";
    int maxi=0;
    int left=0;
    int right=0;
    unordered_map<char, int> mp;
    for (int i=0;i<s.size();i++){
        mp[s[i]]++;
        
        while(mp[s[i]]>1){
            mp[s[left]]--;
            left++;vali
            
        }
        maxi=max(maxi,i-left+1);

    }
    cout<< maxi;
}