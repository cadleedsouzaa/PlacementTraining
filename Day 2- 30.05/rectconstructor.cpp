// create a class called rectanlge with objects int length and and int breadth , now u create 2 objects rectangel of r1 and r2
// then add both, length to length and breadth to breadth. 
// define ur own constructor

#include <bits/stdc++.h>
using namespace std;

class Rect{
    public:
    int l;
    int b;
    Rect(int len,int bre):l(len),b(bre){}
    Rect& operator+(Rect& rhs){
        this->l+=rhs.l;
        this->b+=rhs.b;
        return *this;
    }
};

int main(){
    Rect n1(5,5);
    Rect n2(10,20);
    Rect n3=n1+n2;
    cout << n3.l << ","<<n3.b;
}