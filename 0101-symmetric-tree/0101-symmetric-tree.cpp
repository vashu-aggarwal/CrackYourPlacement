/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* a,TreeNode* b){
        if(a==NULL && b==NULL)
          return true;
        if(a==NULL && b!=NULL || a!=NULL && b==NULL) return false;
        if(a->val==b->val){
        bool left=solve(a->left,b->right);
        bool right=solve(a->right,b->left);
        return left && right;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return true;
        if(root==NULL || root->left==NULL || root->right==NULL){
            return false;
        }
        return solve(root->left,root->right);
    }
};