#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> nums={1,2,3,4,5,9};
    // 4 3 2 1 
    // 9 5
    // 5 9 1 2 3 4 
    int k=4;
    int n=nums.size();

    reverse(nums.begin(),nums.begin()+n-k);
    reverse(nums.begin()+n-k,nums.begin()+n);
    reverse(nums.begin(),nums.end());
    for (int x:nums){
        cout << x << " ";
    }
}