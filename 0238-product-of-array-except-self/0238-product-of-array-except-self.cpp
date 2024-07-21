class Solution {
public:
    int product(vector<int>& nums) {
    int p = 1;
    for (int i = 0; i < nums.size(); i++) {
        p = p * nums[i];
    }
    return p;
}

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans;
    int p = 1;
    p = product(nums);

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0)
         {
            vector<int> temp = nums;
            temp.erase(temp.begin() + i); 
            int temp_product = product(temp);
            ans.push_back(temp_product);
        } 
        else {
            int j = p / nums[i];
            ans.push_back(j);
        }
    }
    return ans;
}
};