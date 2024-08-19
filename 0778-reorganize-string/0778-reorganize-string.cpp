class Solution {
public:
    string reorganizeString(string s) {
        vector<int>freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        int maxi=INT_MIN;
        for(int i=0;i<26;i++){
            maxi=max(maxi,freq[i]);
        }
        if(maxi > (s.length()+1)/2)
            return "";
        
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                pq.push({freq[i],i+'a'});
            }
        }

        string ans="";
        while(!pq.empty()){
            pair<int,char>  top= pq.top();
            pq.pop();
            if(!pq.empty() && !ans.empty() && ans.back() == top.second){
                pair<int,char>stored = top;
                top=pq.top();
                pq.pop();
                pq.push({stored});
            }
            ans+=top.second;
            top.first = top.first-1;
            if(top.first!=0)
                pq.push({top});
            

        }
        return ans;
    }
};