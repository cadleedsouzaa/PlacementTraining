#include <bits/stdc++.h>
using namespace std;

class S{
    private:
        vector<int> st;
    public:
        void push(int a){
            st.push_back(a);
        }
        void pop(){
            st.pop_back();
        }
        void display(){
            for (int x:st){
                cout << x << " ";
            }
            cout<<endl;
        }
        void top(){
            cout << st[st.size()-1];
        }
};

int main(){
    S s;
    s.push(10);
    s.push(20);

    s.push(30);

    s.push(40);
    s.display();
    s.pop();
    s.pop();
    s.display();
    s.top();


}