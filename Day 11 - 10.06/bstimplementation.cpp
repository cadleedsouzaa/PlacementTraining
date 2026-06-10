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

    void inorder() {
        if (left) left->inorder();
        cout << val << " ";
        if (right) right->inorder();
    }
    void bfs(Tree* root){
        queue<Tree*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                Tree* curr=q.front();
                q.pop();
                cout << curr->val << " ";
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            cout <<endl;
        }
    }
};

int main() {
    Tree* root = new Tree(50);

    root->insert(30);
    root->insert(70);
    root->insert(20);
    root->insert(40);

    // root->inorder();
    root->bfs(root);
}