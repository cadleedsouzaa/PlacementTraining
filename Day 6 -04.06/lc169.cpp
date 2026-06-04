#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v={1,4,1,4,1,4,1,4,1,4,1};
    int ele=-1;
    int count=0;
 
    for (int i=0;i<v.size();i++){
        if(v[i]!=ele && count==0){
            ele=v[i];
            count++;
        }
        if(ele=v[i]) count++;
        else count--;1912202
    }
    cout << ele;
}