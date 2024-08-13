class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char& ch:tasks){
            freq[ch-'A']++;
        }
        sort(begin(freq),end(freq));

        int idealstop=(freq[25]-1)*n;
        
        for(int i=24;i>=0;i--){
            idealstop-=min(freq[i],freq[25]-1);
        }

        if(idealstop>0)
           return idealstop+tasks.size();
        
        return tasks.size();

    }
};

