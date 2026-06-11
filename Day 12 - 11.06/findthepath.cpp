#include <bits/stdc++.h>
using namespace std;
bool found=false;
void dfs(int ind,vector<vector<int>>& list, vector<bool> &vis,int s,int d){
    if(found) return ;
    vis[ind]=true;
    for (auto cur:list[ind]){
        if(cur==d && s==ind){
            found=true;
            return;
        }
        if(!vis[cur]) dfs(cur,list,vis,s,d);
    }
}

main(){
    int n=3;
    vector<vector<int>> mat={{0,1},{1,2},{2,0},{3,1}};
    int s=0;
    int d=3;
    int size=mat.size();
    vector<vector<int>> list(size);
    vector<bool> vis(size+1,false);
    for (auto it:mat){
        list[it[0]].push_back(it[1]);
        list[it[1]].push_back(it[0]);

    }
    dfs(0,list,vis,s,d);
    cout<<found;
}