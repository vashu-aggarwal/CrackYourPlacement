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
class BSTIterator {
public:
    stack<int> st;
    stack<int> st1;
    TreeNode* head;

    BSTIterator(TreeNode* root) {
        head=root;
        solve(head);
        while(!st.empty()){
        st1.push(st.top());
        st.pop();
    }
    }


    
    void solve(TreeNode* head){
        if(head==NULL)
            return ;
        solve(head->left);
        st.push(head->val);
        solve(head->right);
    }

    
    int next() {
        int a=st1.top();
        st1.pop();
        return a;
    }
    
    bool hasNext() {
        if(!st1.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */