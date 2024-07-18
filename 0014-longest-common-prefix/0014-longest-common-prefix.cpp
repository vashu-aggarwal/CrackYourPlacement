class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string test = strs[0]; 
        for (int i = 1; i < strs.size(); i++) {
            string current = strs[i];
            int j = 0;        
            while (j < test.size() && j < current.size() && test[j] == current[j]) {
                j++;
            }
            test = test.substr(0, j);
            
            if (test.empty()) return "";
        }
        return test;
    }
};
