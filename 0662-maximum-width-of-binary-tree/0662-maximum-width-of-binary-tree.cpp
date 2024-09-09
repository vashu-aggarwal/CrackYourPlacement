class Solution {
public:
    typedef unsigned long long ll;
    
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});
        ll ans = 0;
        
        while (!q.empty()) {
            int n = q.size();
            ll L = q.front().second; 
            ll R = q.back().second; 
            
            ans = max(ans, R - L + 1);
            
            while (n--) {
                pair<TreeNode*, ll> p = q.front();
                q.pop();
                TreeNode* node = p.first;
                ll i = p.second;
                
                if (node->left) {
                    q.push({node->left, 2 * i + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * i + 2});
                }
            }
        }
        
        return ans;
    }
};
