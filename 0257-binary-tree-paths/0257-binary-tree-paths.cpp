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
    void solve(TreeNode* root,vector<string>& ans,string output){
        if(root==NULL)
           return;
        if(root->left==NULL&& root->right==NULL){
            output+=to_string(root->val);
            ans.push_back(output);
            return;
        }
        output += to_string(root->val) + "->";
        solve(root->left,ans,output);
        solve(root->right,ans,output);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string output="";
        solve(root,ans,output);
        return ans;
    }
};