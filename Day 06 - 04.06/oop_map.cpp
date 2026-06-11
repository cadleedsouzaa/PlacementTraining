#include<bits/stdc++.h>
using namespace std;
class person{
    string name;
    string id;
    string dob;
    int age;
    string address;
};

class admin:public person{
    protected:
        int n;
};

class admin2:public admin{

};
int main(){
    admin2 a;
    a.n=2.5
    //will this work or not s 
}