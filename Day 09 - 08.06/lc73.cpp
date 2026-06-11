#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> v={{1,1,1},{1,0,1},{1,1,1}};
    int n=v.size();
    int m=v[0].size();
    vector<int> row(n,1);
    vector<int> col(m,1);

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if(v[i][j]==0){
                row[i]=0;
                col[j]=0;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if(row[i]==0 || col[j]==0){
                v[i][j]=0;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<v[i][j]<< " ";

        }
        cout << endl;
    }
}
