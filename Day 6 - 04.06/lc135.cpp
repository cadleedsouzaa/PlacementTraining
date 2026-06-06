#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int> ratings={5,4,3,5,6,2};

    int n=ratings.size();
    vector<int> candies(n,1); //store our answer array 1 1 1 2 3 1
    //left pass 
    for (int i=1;i<n;i++){
        if(ratings[i]>ratings[i-1]){
            candies[i]=candies[i-1]+1;
        }
    }
    // after left pass - 3 2 1 2 3 1 (candies) = 12 
    //right pass
    //ratings={5,4,3,5,6,2}
    for (int i=n-2;i>=0;i--){
        if(ratings[i]>ratings[i+1]){
            candies[i]=max(candies[i],candies[i+1]+1);
        }
    }

    int res=0;
    for (int x:candies){
        res+=x;
    }
    cout << res;
    return 0;
}