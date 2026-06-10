#include <bits/stdc++.h>
using namespace std;     

class Tree {
public:
    int val;
    Tree* left;
    Tree* right;

    Tree(int x) {
        val = x;
        left = right = nullptr;
    }

    void insert(int x) {
        if (x < val) {
            if (left == nullptr)
                left = new Tree(x);
            else
                left->insert(x);
        }
        else {
            if (right == nullptr)
                right = new Tree(x);
            else
                right->insert(x);
        }
    }

    void inorder(int& k) {
        if (left) left->inorder(k);
        k--;
        if(k==0){
            cout << val;
        }
        if (right) right->inorder(k);
    }
};

int main() {
    Tree* root = new Tree(3);

    root->insert(1);
    root->insert(4);
    root->insert(2);
    root->insert(50);
    root->insert(42);
    root->insert(10);
    int k=5;
    root->inorder(k);
}