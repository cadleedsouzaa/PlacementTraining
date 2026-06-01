#include <bits/stdc++.h>
using namespace std;

class Animal{
    public:
    virtual    void sound(){
            cout <<"Animal Sound ";

        }
};

class dog:public Animal{
    public:
        void sound(){
            cout << "BOW BOW "<<endl;
        }
};

int main(){
    Animal* a=new dog; //if it binds to the type its called static binding, if to obect then its called dynamic binding 
    a->sound();
}