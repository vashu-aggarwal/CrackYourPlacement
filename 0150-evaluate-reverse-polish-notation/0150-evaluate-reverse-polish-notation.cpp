class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int c; 
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
 
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();

                if(tokens[i] == "+") {
                    c = b + a;
                } else if(tokens[i] == "-") {
                    c = b - a;
                } else if(tokens[i] == "*") {
                    c = b * a;
                } else {
                    c = b / a;
                }

                s.push(c);
            } else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};
