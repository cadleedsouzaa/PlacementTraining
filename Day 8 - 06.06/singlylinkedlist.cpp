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

void addatstart(Node* &head,int val){
    Node* n0=new Node(val);
    n0->next=head;
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
}

void deletebegin(Node* &head){
    if(head==nullptr) return ;
    Node* temp=head;
    head=temp->next;
    delete temp;
}

void deletemiddle(Node* head,int pos){
    Node* temp=head;
    int count=1;
    while(pos-1!=count){
        count++;
        temp=temp->next;
    }
    Node* temp2=temp->next->next;
    temp->next=temp2;
}

void deleteend(Node* &head){
    if(head==nullptr){
        return ;
    }
    Node* prev;
    Node* curr=head;
    while(curr->next){
        prev=curr;
        curr=curr->next;
    }
    prev->next=nullptr;
    delete curr;
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
    cout << "After adding at start : "<<endl;
    addatstart(head,1);
    traverse(head);
    cout << endl;
    cout << "After adding at end : "<<endl;
    addtoend(head,100);
    traverse(head);
    cout <<endl;
    cout << "After deleting at start : "<<endl;
    deletebegin(head);
    traverse(head);
    cout <<endl;
    cout << "After deleting at desired position : "<<endl;
    deletemiddle(head,3);
    traverse(head);
    cout <<endl;
    cout << "After deleting at end : "<<endl;

    deleteend(head);
    traverse(head);
    return 7;
}