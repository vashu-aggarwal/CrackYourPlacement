class Solution {
public:
    int solve(vector<int>& prices,int index,int buy,vector<vector<int>>& dp)
    {
        if(index==prices.size()) return 0;

        if(dp[index][buy]!=-1)
           return dp[index][buy];
        int ans=0;
        if(buy)
        {
            int include= -prices[index]+solve(prices,index+1,0,dp);
            int exclude=solve(prices,index+1,1,dp);
            ans=max(include,exclude);
        }
        else{
            int include= prices[index]+solve(prices,index+1,1,dp);
            int exclude=solve(prices,index+1,0,dp);
            ans= max(include,exclude);
        }
        return dp[index][buy]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,0));
        // return solve(prices,0,1,dp);
        // int buy=1;
        // for(int index=n-1;index>=0;index--)
        // {
        //     for(int buy=0;buy<=1;buy++)
        //     {
        //         int ans=0;
        //     if(buy)
        //     {
        //         int include= -prices[index]+dp[index+1][0];
        //         int exclude=dp[index+1][1];
        //         ans=max(include,exclude);
        //     }
        //     else{
        //         int include= prices[index]+dp[index+1][1];
        //         int exclude=dp[index+1][0];
        //         ans= max(include,exclude);
        //        }
        //          dp[index][buy]=ans;
        //     }
            
           
        // }

        // return dp[0][1];
        vector<int> curr(2,0);
        vector<int> next(2,0);
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int ans=0;
            if(buy)
            {
                int include= -prices[index]+next[0];
                int exclude=next[1];
                ans=max(include,exclude);
            }
            else{
                int include= prices[index]+next[1];
                int exclude=next[0];
                ans= max(include,exclude);
               }
                 curr[buy]=ans;
            }

            next=curr;
           
        }

        return next[1];
    }
};