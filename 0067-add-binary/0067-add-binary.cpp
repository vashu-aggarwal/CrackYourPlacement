#include <string>
#include <algorithm>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        int carry = 0;
        string result = "";
        int i = 0, j = 0;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        while (i < a.length() || j < b.length() || carry) {
            int sum = carry;
            if (i < a.length()) sum += a[i++] - '0';
            if (j < b.length()) sum += b[j++] - '0';
            
            result += (sum % 2) + '0';
            carry = sum / 2;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
