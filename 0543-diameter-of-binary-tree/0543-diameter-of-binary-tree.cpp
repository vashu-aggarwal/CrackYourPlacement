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

    int maxi(TreeNode* root)
    {
        if(!root) return 0;
        int maxLeft = maxi(root->left);
        int maxRight = maxi(root->right);
        return max(maxLeft, maxRight)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        return 0;
        int left=maxi(root->left);
        int right=maxi(root->right);

       int op1=diameterOfBinaryTree(root->left);
       int op2=diameterOfBinaryTree(root->right);


        return max(max(op1,op2),left+right);
    }
};