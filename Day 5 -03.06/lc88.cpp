#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums1={1,2,3,0,0,0};
    vector <int> nums2={2,5,6};

    int m=3;
    int n=3;
    int k=nums1.size()-1;

    int i=m-1;
    int j=n-1;

    while(i>=0 && j>=0){
        if(nums1[i]>nums2[j]){
            nums1[k]=nums1[i];
            i--;
        }
        else{
            nums1[k]=nums2[j];
            j--;
        }
        k--;
    }
    for(int x:nums1){
        cout << x << endl;
    }
    return 0;
}