class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];

        int i = 0;
        int j = 0;
        string test = "";
        
        while (i < strs[0].length() && j < strs[1].length()) {
            if (strs[0][i] == strs[1][j]) {
                test.push_back(strs[0][i]);
                i++;
                j++;
            } else {
                break;
            }
        }

        for (int k = 2; k < strs.size(); k++) {
            string check = strs[k];
            string temp = "";
            int m = 0;
            int n = 0;
            while (m < test.size() && n < check.size()) {
                if (!test.empty() && test[m] == check[n]) {
                    temp.push_back(test[m]);
                    m++;
                    n++;
                } else {
                    break;
                }
            }
            test = temp;
        }

        return test;
    }
};
