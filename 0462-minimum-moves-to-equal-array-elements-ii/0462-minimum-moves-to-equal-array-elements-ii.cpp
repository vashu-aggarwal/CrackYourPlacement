class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=(nums[0]+nums[n-1])/2;
        int i=0,j=n-1;
        int ans=0;
        while(i<j){
            ans+=(mid-nums[i])+(nums[j]-mid);
            i++;
            j--;
        }

        return ans;
    }
};