#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    Node():next(nullptr){};
    
    Node(auto val){
        data=val;
        next=nullptr;
    }

};
void traverse(Node* head){
    while(head){
        cout << head->data << "-> ";
        head=head->next;
    }
    cout <<"NULL";
}

void rotatelist(Node* &head,int k){
    cout<<"rotate func start";
    int count=1;
    Node* temp=head;
    while(temp->next!=nullptr){
        count++;
        temp=temp->next;
    }
    temp->next=head;
    Node* a=head;
    k=k%count;
    for (int i=0;i<count-k;i++){
        temp=temp->next;
    }
    a=temp->next;
    temp->next=nullptr;
    head=a;
}
    
int main(){
    Node* head;
    Node* n1=new Node(5);
    head=n1;
   
    Node* n2=new Node(10);
    Node* n3=new Node(15);
    Node* n4=new Node(20);
    Node* n5=new Node(25);
    Node* n6=new Node(30);
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    cout << "Original List : "<<endl;
    traverse(head);
    cout << endl;
    rotatelist(head,3);
    cout << endl;
    cout<<"Rotated List : " <<endl;
    traverse(head);

}