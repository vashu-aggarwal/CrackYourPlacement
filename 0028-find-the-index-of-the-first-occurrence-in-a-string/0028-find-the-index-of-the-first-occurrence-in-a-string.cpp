class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if (needle.size()>haystack.size())
            return -1;
        
        int i, j;
        
        for (i = 0; i <= haystack.length() - needle.length(); ++i) {
            
            for (j = 0; j < needle.length(); ++j) {
                if (haystack[i + j] != needle[j])
                    break; 
            }
            
            if (j == needle.length())
                return i;
        }
        
        return -1;
    }
};
