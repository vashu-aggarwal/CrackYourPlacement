class Solution {
public:
    bool solve(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) return false;
        if (isIdentical(root, subRoot)) return true;
        return solve(root->left, subRoot) || solve(root->right, subRoot);
    }

    bool isIdentical(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL) return true;
        if (root == NULL || subRoot == NULL) return false;
        return (root->val == subRoot->val) &&
               isIdentical(root->left, subRoot->left) &&
               isIdentical(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return solve(root, subRoot);
    }
};
