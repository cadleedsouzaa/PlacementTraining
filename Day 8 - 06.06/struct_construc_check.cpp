#include <bits/stdc++.h>
using namespace std;
//1) whether we can write a constructor for struct
//2) how to invoke the constructor 
//yogeshwar thirumurthy 

struct dog{
    string name;
};

class animal{
    public:
        string variant;
        animal(){
            this->variant="we are idiots";
            cout<<this->variant<<endl;
        }
        ~animal(){
            delete this;
        }
        
};

int main(){
    animal* a=new animal;
    struct dog* b=(dog*) malloc (sizeof(dog)*1);
}