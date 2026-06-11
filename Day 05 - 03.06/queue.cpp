#include <bits/stdc++.h>
using namespace std;

class Q{
    private:
        vector<int> q;
    public:
        void push(int a){
            q.push_back(a);
        }
        void pop(){
            q.erase(q.begin(),q.begin()+1);
        }
        void front(){
            cout <<  q[0] << endl;
        }

};

int main(){
    Q q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.front();
    q.pop();
    q.front();
}