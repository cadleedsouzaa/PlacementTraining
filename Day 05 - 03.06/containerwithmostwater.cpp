#include <bits/stdc++.h>
using namespace std;


int main(){
    vector<int> height={13,5,1,8,3,9};
    int maxi=INT_MIN;
    int n=height.size()-1;
    int l=0;
    int r=n-1;

    while(l<r){
        int area=(abs(l-r)* min(height[l],height[r]));
        maxi=max(area,maxi);
        if(height[l]<height[r]){
            l++;
        }
        else{
            r--;
        }
    }
    cout << " max area is : "<<maxi;
    
}