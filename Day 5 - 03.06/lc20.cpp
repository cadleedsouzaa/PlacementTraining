#include<bits/stdc++.h>
using namespace std;

int main(){
    string s="([{[()]}])";
    stack <char> st;
    for (char &ch : s){
        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }
        else if(ch==')'&& st.top()=='('){
            st.pop();
        }
        else if(ch==']'&& st.top()=='['){
            st.pop();
        }
        else if(ch=='}'&& st.top()=='{'){
            st.pop();
        }
    }
    if(st.empty()){
        cout<<"valid";
    }
    else{
        cout<<"not valid";
    }
    return 10;
}