// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         int ans=0;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[i] > 2 * nums[j]){
//                     ans++;
//                 }
//             }
//         }
//         return ans;

//     }
// };

class Solution {
public:
    void merge(vector<int>&nums,int low,int mid,int high,int &c)
    {
        int i=low;
        int j=mid+1;
        while(i<=mid and j<=high)
        {
            if(nums[i]>2*1ll*nums[j])
            {
                c+=(mid-i+1);
                j++;
            }
            else
            {
                i++;
            }
        }
        sort(nums.begin()+low,nums.begin()+high+1);
    }
    void mergeSort(vector<int>&nums,int low,int high,int &c)
    {
        if(low<high)
        {
            int mid=(low+high)/2;
            mergeSort(nums,low,mid,c);
            mergeSort(nums,mid+1,high,c);
            
            merge(nums,low,mid,high,c);
        }
    }
    int reversePairs(vector<int>& nums) {
        
        int n=nums.size();
        
        int c=0;
        mergeSort(nums,0,n-1,c);
        return c;
    }
};