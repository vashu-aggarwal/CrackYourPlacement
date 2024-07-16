class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0,j=1,k=2,l=n-1;
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            int j=i+1;
            int l=n-1;
            while(j<l){
            int k=j+1;
            l=n-1;
            while(k<l){
                long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                if(sum<target){
                    k++;
                }
                else if(sum>target){
                    l--;
                }
                else{
                    s.insert({nums[i],nums[j],nums[k],nums[l]});
                    k++;
                    l--;
                }
            }

            

            j++;
        }       
    }
        for(auto it:s)
             ans.push_back(it);
    
    return ans;

    }
};