#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums={74,52,14,2,36,988,2,14,5,26,54,7};
    vector<int> a={1,2,3};
    a.push_back(2);
    a.push_back(2);

    cout<< a.size();
    int k=3;
    int sum=0;
    int maxi=INT_MIN;
    for (int i=0;i<k;i++){
        sum+=nums[i];
    }
    int left=0;
    maxi=max(sum,maxi);
    for (int i=k;i<nums.size();i++){
        sum+=nums[i];
        sum-=nums[left++];
        maxi=max(maxi,sum);
    }
    cout<<"answer is : "<<maxi<<endl;
    
}