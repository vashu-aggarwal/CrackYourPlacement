class Solution {
public:
    int minDeletions(string s) {
       vector<int> freq(26,0);

       for(char c:s){
          freq[c-'a']++;
       }
       
       sort(freq.begin(),freq.end());
       int ans=0;
       unordered_map<int,int> mp;
       for(int i=0;i<freq.size();i++){
        if(freq[i]==0) continue;
        while(mp.find(freq[i])!=mp.end()){
            freq[i]--;
            ans++;
        }
        if(freq[i]!=0)
           mp[freq[i]]++;
       }

       return ans;
    }
};