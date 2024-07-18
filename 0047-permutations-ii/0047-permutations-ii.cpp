class Solution {
public:
    void solve(int index,vector<int> input,vector<vector<int>>& ans){
        if(index>=input.size()){
             
             ans.push_back(input);
             return;
        }

        for(int i=index;i<input.size();i++){
            if(input[index]!=input[i] || index==i){
                swap(input[index],input[i]);
                solve(index+1,input,ans);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& input) {
        sort(input.begin(),input.end());
        vector<vector<int>> ans;
        
        solve(0,input,ans);
        return ans;
    }
};