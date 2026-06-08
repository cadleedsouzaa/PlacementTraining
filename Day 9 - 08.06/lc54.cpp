#include <bits/stdc++.h>
using namespace std;
//HOMEWORRK

int main(){
    vector<vector<int>> v={{1,2,3},{4,5,6},{7,8,9}};
    int n=v.size();
    int m=v[0].size();
    int tl=0;
    int tr=m-1;
    int bl=0;
    int br=n-1;

    while(tl>= bl && tr>=br){
        int l=tl;
        while(tl<=tr){
            ans.push_back(v[tl][l]);
            l++;
        }
        tl++;
        int r=tr;
        while(tr<br){
            ans.push_back(v[r][br]);
            r++;
        }
        int l=br;
        while(br>tl){

        }


    }
}