#include <bits/stdc++.h>
using namespace std;

class Complex{
    public:
    int real;
    float img;  
    Complex(int r,float i):real(r),img(i){}
    Complex& operator+(Complex& rhs){
        cout<<this->real<<endl;
        cout<<this->img<<endl;
        return *this;
    }
};

int main(){
    Complex number1(5,10.5);
    Complex number2(10,20.5);
    Complex number3=number1+number2;


}

