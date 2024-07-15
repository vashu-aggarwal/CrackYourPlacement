https://leetcode.com/problems/sort-colors/description/

class Solution {
public:
    void sortColors(vector<int>& nums) {
            int low=-1,high=nums.size()-1,mid=0;
            while(mid<=high)
            {
                
                if(nums[mid]==0)
                {
                    
                    low++;
                    swap(nums[low],nums[mid]);
                    mid++;
                }
                 else if (nums[mid]==1)
                {
                   mid++;
                }
                else{
                    swap(nums[mid],nums[high]);
                    high--;
                    
                }
            }
    }
};
