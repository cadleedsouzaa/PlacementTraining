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
string same="true";
void check(TreeNode* root1,TreeNode*root2){
    if(same=="false") return;
    if(!root1 && !root2) return;
    
    if(!root1 && root2  ||  root1 && !root2){
        same="false";
        return ;
    }
    if(root1->val!=root2->val){
        same="false";
        return;
    }
    check(root1->left,root2->left);
    check(root1->right,root2->right);
}
int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    TreeNode *root1=new TreeNode(1);
    root1->left=new TreeNode(2);
    root1->right=new TreeNode(3);

    
    check(root,root1);
    cout<<same;

}