class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

       
        int k=0;
        int i=1;
        while(i<nums.size()){
            if(nums[i]!=nums[i-1]){
                nums[k]=nums[i-1];
                k++;
                
            }
            i++;
        }
        nums[k++]=nums[i-1];
        return k;
    }
};