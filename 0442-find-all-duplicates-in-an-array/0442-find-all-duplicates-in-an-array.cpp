class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // unordered_map<int,int> mp;
        // for( auto num:nums) mp[num]++;
        // vector<int> ans;
        // for(auto it:mp)
        // {
        //     if(it.second>1)
        //     {
        //         ans.push_back(it.first);
        //     }
        // }

        // return ans;

        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int inx=abs(nums[i]);
            if(nums[inx-1]<0)
            {
                ans.push_back(inx);
            }
            else{
               nums[inx-1]= nums[inx-1]*(-1);
            }
        }
        return ans;
        
    }
};