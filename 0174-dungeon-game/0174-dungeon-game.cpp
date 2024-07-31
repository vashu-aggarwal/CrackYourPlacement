#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int solve(int i, int j, int m, int n, const vector<vector<int>>& grid, vector<vector<int>>& dp) {
       
        if (i >= m || j >= n) return INT_MAX; 

        if (i == m - 1 && j == n - 1) return grid[i][j]>0?1:1-grid[i][j]; 
        
        
        if (dp[i][j] != -1) return dp[i][j];

        
        int right = solve(i, j + 1, m, n, grid, dp);
        int down = solve(i + 1, j, m, n, grid, dp);

        
        int ans =  min(right, down)-grid[i][j];
        return dp[i][j]=ans>0?ans:1;
    }

    int calculateMinimumHP(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
         return solve(0, 0, m, n, grid, dp);
        
    }
};

