class Solution {
public:
    bool solve(vector<int>& nums,int index,vector<int>& dp){
        if(index>=nums.size()-1)
           return true;


        if(dp[index]!=-1){
            return dp[index];
        }
        
        int power=nums[index];
        bool result=false;
        for(int i=1;i<=power;i++){
            result = result | solve(nums,index+i,dp);
            if(result) break;
        }

        return dp[index]=result;
    }
    bool canJump(vector<int>& nums) {
        if(nums[0]==0 && nums.size()==1) return true;
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(nums,0,dp);
    }
};