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
    check(root1->left,root2->right);
    check(root1->right,root2->left);
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

    check(root->left,root->right);
    
    cout<<same;

}