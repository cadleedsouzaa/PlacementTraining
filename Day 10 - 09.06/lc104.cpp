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
int level=0;

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
            if(curr->left!=nullptr){
                q.push(curr->left);
            }
            if(curr->right!=nullptr){
                q.push(curr->right);
            }
        }
        level++;
        cout <<endl;
    }
}

int  othermethod(TreeNode* root){
    if(root==nullptr) return 0;

    int left=othermethod(root->left);
    int right=othermethod(root->right);
    int res=1+max(left,right);
    return res;
}
int main(){
    TreeNode *root=new TreeNode(1);
    TreeNode* one=new TreeNode(2);
    TreeNode* two=new TreeNode(2);
    root->left=one;
    root->right=two;
    one ->left=new TreeNode(3);
    one ->right=new TreeNode(4);
    two ->left=new TreeNode(4);
    two->right=new TreeNode(3);
    one->left->left=new TreeNode(100);

    bfs(root);
    cout<<level;
    int ans=othermethod(root);
    cout <<endl;
    cout << ans;
}