#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> strs={"flower","flow","flight"};
    sort(strs.begin(),strs.end());
    string chk1=strs[0];
    string chk2=strs[strs.size()-1];
    string ans="";
    int minl=min(chk1.size(),chk2.size());
    for (int i=0;i<minl;i++){
        if(chk1[i]==chk2[i]){
            ans+=chk1[i];
        }
        else{
            break;
        }
    }
    cout << ans
}
//7 77 84 32 45 98 95 92 35 36 38
