class Solution {
public:
    
    int dp[1001][1001];
    int mod = 1000000000+7;
    int dfs(int i, int j, string &s) {
        if(i > j) return 0;
        if(i==j) return 1;
        if(dp[i][j]) return dp[i][j];
        int ans=0;
        if(s[i]==s[j]) {
            ans = 2*dfs(i+1,j-1,s);
            int l=i+1, r=j-1;
            while(l<=r and s[l]!=s[i]) l++;
            while(l<=r and s[r]!=s[j]) r--;
            if(l < r) ans-=dfs(l+1,r-1,s);
            else if(l==r) ans++;
            else ans+=2;
        }
        else ans = dfs(i+1,j,s)+dfs(i,j-1,s)-dfs(i+1,j-1,s);
        return dp[i][j] = ans < 0 ? (ans+mod) % mod : ans % mod;
    }
    
    int countPalindromicSubsequences(string s) {
        memset(dp,0,sizeof(dp));
        return dfs(0,s.size()-1,s);
    }
};