class Solution {
public:
    int solve(int e,int f,vector<vector<int>>& dp){
        if(e==1)
           return f;
        
        if(f==1 || f==0)
          return f;
        
        if(dp[f][e]!=-1)
           return dp[f][e];
        int mini=INT_MAX;
        int l=1,h=f,temp=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            int left=solve(e-1,mid-1,dp);
            int right=solve(e,f-mid,dp);
            temp=1+max(left,right);
            if(left<right){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
            mini=min(mini,temp);
        }

        return dp[f][e]=mini;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(k,n,dp);
    }
};