class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> curr(2,vector<int>(k+1,0));
        vector<vector<int>> next(2,vector<int>(k+1,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int limit=1;limit<=k;limit++)
                {
                    int ans=0;
                    if(buy)
                    {
                        int include= -prices[index]+next[0][limit];
                        int exclude=next[1][limit];
                        ans=max(include,exclude);
                    }
                    else{
                        int include= prices[index]+next[1][limit-1];
                        int exclude=next[0][limit];
                        ans= max(include,exclude);
                    }
                    curr[buy][limit]=ans;
                }
            }
            next=curr;
        }

        return next[1][k];
    }
};