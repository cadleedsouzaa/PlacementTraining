#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter n";
    cin >> n;
    for(int i=1;i<=n;i++){
        for (int j=0;j<n*2;j++){
            if(j==i||j==n*2-i){
                cout << "*";
            }
            else{
                cout<< " ";
            }

        }
        cout<<endl;
    }
    return 0;
}