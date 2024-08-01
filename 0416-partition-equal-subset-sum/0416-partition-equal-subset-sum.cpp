class Solution {
public:
    // bool solve(vector<int>& nums,int target,int index,vector<vector<int>>& dp)
    // {
    //     if(index>=nums.size())
    //     {
    //         return false;
    //     }

    //     if(target==0)
    //     {
    //         return true;
    //     }
    //     if(target<0)
    //     {
    //         return false;
    //     }
    //     if(dp[index][target]!=-1)
    //     {
    //         return dp[index][target];
    //     }
    //     bool include=solve(nums,target-nums[index],index+1,dp);
    //     bool exclude=solve(nums,target,index+1,dp);

    //     return dp[index][target]=include || exclude;
    // }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 != 0) return false;
        int n = nums.size();
        int target = sum / 2;
    //     vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    //     for (int i = 0; i <= n; i++) {
    //         dp[i][0] = true;
    //     }

    //     for (int index = n - 1; index >= 0; index--) {
    //         for (int t = 1; t <= target; t++) {
    //             bool include = false;
    //             if (t - nums[index] >= 0)
    //                 include = dp[index + 1][t - nums[index]];
    //             bool exclude = dp[index + 1][t];

    //             dp[index][t] = include || exclude;
    //         }
    //     }

    //     return dp[0][target];
    // }
    vector<int> curr(sum+1,0);
    vector<int> next(sum,0);
        curr[0]=1;
        next[0]=1;

        for (int index = n - 1; index >= 0; index--) {
            for (int t = 1; t <= target; t++) {
                bool include = false;
                if (t - nums[index] >= 0)
                    include = next[t - nums[index]];
                bool exclude = next[t];

                curr[t] = include || exclude;
            }
            next=curr;
        }

        return  curr[target];
    }


};