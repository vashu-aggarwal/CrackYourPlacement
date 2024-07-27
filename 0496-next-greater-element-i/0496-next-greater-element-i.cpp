class Solution {
public:
    int solve(vector<int> nums2,int key){
        stack<int> st;
        st.push(-1);
        int j=0;
        for(int i=nums2.size()-1;i>=0;i--){
            while(nums2[i]>key){
                st.push(nums2[i]);
                i--;
            }
            if(nums2[i]==key){
                break;
            }
        }
        
           return st.top();
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            int value=solve(nums2,nums1[i]);
            ans.push_back(value);
        }

        return ans;
    }
};