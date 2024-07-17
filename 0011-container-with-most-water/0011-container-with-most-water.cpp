class Solution {
public:
    int maxArea(vector<int>& arr) {
        int i=0,j=arr.size()-1,area=0;
        int ans=INT_MIN;
        while(i<j)
        {
            if(arr[i]<arr[j])
            {
                area=abs(i-j)*arr[i];
                i++;
            }
            else{
                area=abs(i-j)*arr[j];
                j--;
            }
            ans=max(ans,area);
        }
        return ans;
    }
};