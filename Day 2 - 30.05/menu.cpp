#include <bits/stdc++.h>
using namespace std;
void Register(){
{
                string username,userid,password;
                cout << "Enter username : ";
                cin >> username;
                cout << endl;
                cout << "Enter Used ID : ";
                cin >> userid;
                cout << endl;

                cout << "Enter Password : ";
                cin  >> password;
                cout << endl;}
}

void login(){
    {
                string userid,password;
                cout << "Enter Used ID : ";
                cin >> userid;
                cout << endl;

                cout << "Enter Password : ";
                cin  >> password;
                cout << endl;

                cout <<"Login Successful!";}
}

void admin(){
    {
                string adminid,adminpassword;
                cout << "Enter Admin ID : ";
                cin >> adminid;
                cout << endl;

                cout << "Enter Admin Password : ";
                cin  >> adminpassword;
                cout << endl;

                cout<<"Admin Login Successful ";}
}
int main(){
    int n;
    while(true){
        cout << " 1. Register 2. Login 3. Admin Login 4. LogOut 5. Exit  : ";
        cin >> n;
        if(n==5){
            break;
        }
        switch(n){
            case 1:
            Register();
                break;
            case 2:
            login();
                break;
            
            case 3:admin();
                break;
            case 4:
                cout<<"Logged out succesfully!!";
                break;
            
            



        }
    }
    return 0;
}