#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[5]={1,2,3,4,5};
    bool flag=false;
    for (int i=0;i<sizeof(arr);i++){
        if(arr[i]==2){
            arr[i]=-1;
            flag=true;
        }
    }
    if(flag){
        cout << "exists";
    }
    else{
        cout << "doesnt exist";
    }
    for (int i=0;i<sizeof(arr);i++){
        cout << arr[i]<<endl;
    }
    return 0;

}