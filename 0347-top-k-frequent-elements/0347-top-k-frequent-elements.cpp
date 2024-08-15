class Solution {
public:
    static bool operator()(pair<int,int>& a,pair<int,int>& b){
        if(a.second==b.second){
            return true;
        }

        return a.second<b.second;
        
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,Solution> pq;

        for(auto& it:mp){
            pq.push({it.first,it.second});
        }
        vector<int> ans;
        while(k--){
            pair<int,int> top=pq.top();
            pq.pop();

            ans.push_back(top.first);
        }

        return ans;
    }
};