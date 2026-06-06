#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums={2,7,11,15};

    int l=0;
    int r=nums.size()-1;
    int target=9;
    vector<int> res;
    while(l<r){
        int sum=nums[l]+nums[r];
        if(sum==target){
            cout<<l+1<<" " << r+1;
            res.push_back(l+1,r+1);
            break;  
        }
        else if(sum>target){
            r--;
        }
        else{
            l++;
        }
    }
    return 0;
}