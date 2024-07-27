class Solution {
public:
    int solve(vector<string>& strs, int m, int n, int index, vector<vector<vector<int>>>& dp) {
        if (index == strs.size())
            return 0;

        if (dp[index][m][n] != -1)
            return dp[index][m][n];

        
        int not_take = solve(strs, m, n, index + 1, dp);

        
        int take = 0;
        string s = strs[index];
        int zeroes = count(s.begin(), s.end(), '0');
        int ones = count(s.begin(), s.end(), '1');

        if (m >= zeroes && n >= ones) {
            
            take = 1 + solve(strs, m - zeroes, n - ones, index + 1, dp);
        }

        
        return dp[index][m][n] = max(not_take, take);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(strs, m, n, 0, dp);
    }
};
