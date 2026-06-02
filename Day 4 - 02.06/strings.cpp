#include <bits/stdc++.h>
using namespace std;

string substr(int s,int e,string og){
    string res;
    for (int i=s;i<e;i++){
        res+=og[i];
    }
    return res;
}
int size(string og){
    int cnt=0;
    for (char &ch:og){
        cnt++;
    }
    return cnt;
}
int find(string og,string target){
    // int target_size=target.size();
    // int temp=target_size;
    // vector<char> res;
    // int idx=0;
    // int og_idx=0;
    // for (char &ch : target){
    //     res.push_back(ch);
    // }
    // if(og.size()< target.size()){
    //     return -1;
    // }
    // for (char &ch:og){
    //     if(temp=0){
    //         return og_idx-target_size;
    //     }
    //     else if (idx < target_size && ch==res[idx]){
    //         temp--;
    //         idx++;
    //     }
    //     else{
    //         temp=target_size;
    //         idx=0;
    //         if(ch==res[idx]){
    //             temp--;
    //             idx++;
    //         }

    //     }
    //     og_idx++;
    //     if(temp==0){
    //         return og_idx-target_size;
    //     }
    // }
    // return -1;
    int target_size=target.size();
    int temp=target_size;
    int idx=0;
    for (int i=0;i<og.size();i++){
        if(og[i]!=target[idx] && temp>0){
            temp=target_size;
            idx=0;
        }else{
            temp--;
            idx++;
        }
        if(temp==0){
            return i-target_size+1;
        }
    }
    return -1;
}

string append(string str1, string str2){
    string res;
    res=str1+str2;
    return res;
}
int main(){
    // string name,dept,class_no;
    // cout << "enter name & department & class number : ";
    // getline(cin,name);
    // getline(cin,dept);
    // getline(cin,class_no);

    
    // cout << "entered : "<< name << endl << dept << endl<< class_no<< " ";
    string og="cadlee";
    cout <<substr(1,4,og);
    cout << "size of string : "<<size(og)<<endl;
    cout << find(og,"lle")<<endl;
    cout << append("cad","lee");
    return 0;

}