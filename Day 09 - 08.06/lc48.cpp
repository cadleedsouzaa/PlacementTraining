#include <bits/stdc++.h>
using namespace std;
// [ 1 2 3 ]
// [ 4 5 6 ]
// [ 7 8 9 ]


// //[ 7
//     8
//     9]
int main(){
    vector<vector<int>> v={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int n=v.size();
    int m=v[0].size();
    for (int i=0;i<n;i++){
    
        for(int j=i;j<m;j++){
            swap(v[i][j],v[j][i]);
        }
    }
    

    for (int i=0;i<n;i++){
        reverse(begin(v[i]),end(v[i]));
        for(int j=0;j<m;j++){
            cout << v[i][j] << " ";
        } 
        cout <<endl;
    }
}