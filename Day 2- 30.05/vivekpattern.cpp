#include <bits/stdc++.h>
using namespace std;

void printall(int n){
    for (int i=1;i<=n;i++){
        cout << "*";
    }
}

void printfew(int n){
    if(n==1){
        cout << "*";
    }
    else{
        cout << "*";
        for (int i=1;i<=n-2;i++){
            cout <<" ";
        }
        cout <<"*";    }
}

int main(){
    int n;
    cout<<"enter n";
    cin >> n;
    for (int i=1;i<=n;i++){
        if(i==1 || i==n){
            printall(n);
        }
        else{
            printfew(n);
        }
        cout<<endl;
    }
    return 0;
}