class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int,int>> st;
        int n=nums.size(),curr=0,ans=0;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]>st.top().first){
                curr=max(curr+1,st.top().second);
                ans=max(ans,curr);
                st.pop();
            }

            st.push({nums[i],curr});
            curr=0;
        }

        return ans;
    }
};