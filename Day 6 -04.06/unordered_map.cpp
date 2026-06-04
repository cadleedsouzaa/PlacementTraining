#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int,string> mp;
    mp[1]="Apple";
    mp[2]="banana";
    mp[3]="watermelon";
    mp[4]="pineapple";
    mp[5]="strawberry";

    for (auto &pair:mp){
        cout << pair.second <<" " ;
    }
    return 0;

    

    

}