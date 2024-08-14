class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        int i = 0;

        
        for (i = 0; i < num.size(); i++) {
            
            while (!s.empty() && k > 0 && s.back() > num[i]) {
                s.pop_back();
                k--;
            }
            s.push_back(num[i]);
        }
        
        
        while (k > 0 && !s.empty()) {
            s.pop_back();
            k--;
        }
        
       
        int start = 0;
        while (start < s.size() && s[start] == '0') {
            start++;
        }
        
        
        if (start == s.size()) {
            return "0";
        }
        
       
        return s.substr(start);
    }
};
