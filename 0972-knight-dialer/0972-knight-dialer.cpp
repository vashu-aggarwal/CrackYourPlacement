class Solution {
public:
    int MOD=1e9+7;
    int dfs(int remain,int index,vector<vector<int>>& jumps,vector<vector<int>>& dp){
        if(remain==0)
        {
            return 1;
        }
        if(dp[remain][index]!=-1){
            return dp[remain][index];
        }
        int ans=0;
        for(int num:jumps[index]){
            
            ans=(ans+dfs(remain-1,num,jumps,dp))%MOD;
            }
        dp[remain][index]=ans;
        return ans;
    }
    int knightDialer(int n) {
            vector<vector<int>> jumps = {
                {4, 6},
                {6, 8},
                {7, 9},
                {4, 8},
                {3, 9, 0},
                {},
                {1, 7, 0},
                {2, 6},
                {1, 3},
                {2, 4}
            };
            vector<vector<int>> dp(n+1,vector<int>(10,-1));
            int ans=0;
        for(int i=0;i<=9;i++){
             ans=(ans+dfs(n-1,i,jumps,dp))%MOD;
        }
        return ans;
    }
};