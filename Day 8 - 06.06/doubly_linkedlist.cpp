#include <bits/stdc++.h>
using namespace std;
//naxidom 250
class Node{
    public:
        int data;
        Node* prev;
        Node* next;
    Node():next(nullptr),prev(nullptr){};
    
    Node(auto val){
        data=val;
        next=nullptr;
        prev=nullptr;
    }

};

void traverse(Node* head){
    while(head){
        cout << head->data << "-> ";
        head=head->next;
    }
    cout <<"NULL";
}

void addatstart(Node* &head,int val){
    Node* n0=new Node(val);
    n0->next=head;
    head->prev=n0;
    head=n0;
}

void addtoend(Node* &head,int val){
    Node* temp=new Node();
     temp=head;
    Node*  n=new Node(val);
    while(temp->next){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
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

    n2->prev=n1;
    n3->prev=n2;
    n4->prev=n3;
    n5->prev=n4;
    n6->prev=n5;
    traverse(head);
    cout << endl;
    addatstart(head,1);
    traverse(head);
    cout << endl;
    addtoend(head,100);
    traverse(head);
    return 7;
}