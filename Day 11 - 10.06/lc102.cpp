#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):
        val(x),left(nullptr),right(nullptr){};
};

void bfs(TreeNode* root){
    if(root==nullptr){
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        while(n--){
            TreeNode* curr=q.front();
            q.pop();
            cout << curr->val <<endl;
            if(curr->left!=nullptr){
                q.push(curr->left);
            }
            if(curr->right!=nullptr){
                q.push(curr->right);
            }
        }
        cout <<endl;
    }
}

int main(){
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    bfs(root);
    cout<<endl;}