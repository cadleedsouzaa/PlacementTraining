/*                          TREE
in a normal tree u can have more than 2 children, in binary tree u can only have atmost 2 nodes but in binary search tree the 
left side of the root should be less than the root itself and the right side should mbe more than the root itself.
a complete binary search tree at max u can have 2 nodes or 0 nodes.
*/
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
void preorder(TreeNode* root){
    if (root==NULL){
        return;
    }
    cout << root->val << "\t";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root){
    if (root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->val << "\t";
    inorder(root->right);
}
void postorder(TreeNode* root){
    if (root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << "\t";
}
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
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    cout <<"--------DFS---------\n";
    cout<<"preorder : "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"inorder : "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"postorder : "<<endl;
    postorder(root);
    cout<<endl;
    cout <<"---------------------";
    cout<<endl;
    cout<<"----------BFS----------";
    cout<<endl;
    bfs(root);
    cout<<endl;

    

}
