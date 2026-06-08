/* you have an integer array , array [ 1 1 0 1 1 0 0 1 0 0 1] , u can step only on the 1st, you are starting at stand and need to reach end
and u can take max 2 steps. find the minimum number of steps to reach the end of the array 
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v={1,1,0,1,0,1,1,0};
    int n=v.size();
    int c=0;
    int i=0;

    while(i<n-1){
        if(i+2<n && v[i+2]==1){
            i+=2;
            c++;
        }
        else if(i+1<n && v[i+1]==1){
            i+=1;
            c++;
        }
        else{
            break;
        }


    }
    cout << "steps taken is : "<<c;
}
//linked lis 1 2 3 45 find the middle point