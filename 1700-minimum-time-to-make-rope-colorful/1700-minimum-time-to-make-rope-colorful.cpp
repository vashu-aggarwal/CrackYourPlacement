class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int i = 0;
        int j = 1;
        
        while (i < j && j < colors.size()) {
            if (colors[j] == colors[i]) {
                if (neededTime[j] > neededTime[i]) {                    
                    ans += neededTime[i];
                    i = j;
                    j++;
                } else {
                    ans += neededTime[j];
                    j++;
                }
            } else {
                i = j;
                j++;
            }
        }
        
        return ans;
    }
};
