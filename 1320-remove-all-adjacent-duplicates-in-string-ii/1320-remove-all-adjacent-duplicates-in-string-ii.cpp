class Solution {
public:
    string removeDuplicate(string s, int k) {
        stack<char> st;
        stack<int> countStack;  

        for (char c : s) {
            if (!st.empty() && st.top() == c) {
                
                countStack.top()++;
                if (countStack.top() == k) {
                   
                    st.pop();
                    countStack.pop();
                }
            } else {
               
                st.push(c);
                countStack.push(1);
            }
        }

        
        string ans = "";
        while (!st.empty()) {
            ans = string(countStack.top(), st.top()) + ans;
            countStack.pop();
            st.pop();
        }

        return ans;
    }

    string removeDuplicates(string s, int k) {
        stack<char> st;
        stack<int> countStack;  

        for (char c : s) {
            if (!st.empty() && st.top() == c) {
                
                countStack.top()++;
                if (countStack.top() == k) {
                   
                    st.pop();
                    countStack.pop();
                }
            } else {
               
                st.push(c);
                countStack.push(1);
            }
        }

        
        string ans = "";
        while (!st.empty()) {
            ans = string(countStack.top(), st.top()) + ans;
            countStack.pop();
            st.pop();
        }

        return ans;
    }
};
