class Solution {
public:
    bool isNumber(string s) {
        if(s.empty()) return false;

        int i=0;
        if(s[i]=='+' || s[i]=='-')
           i++;
        
        bool interger=false;

        while(i<s.size()&& isdigit(s[i])){
            interger=true;
            i++;
        }

        bool decimal=false;
        if(i<s.size() && s[i]=='.'){
            
            i++;
            while(i<s.size() && isdigit(s[i])){
                decimal=true;
                i++;
            }
        }

        if(i<s.size() && (s[i]=='e' || s[i]=='E')){
            i++;
        if(i<s.size() && (s[i] == '+' || s[i] == '-')) i++;
        if(i==s.size() && !isdigit(s[i]))
            return false;
        
        while(i<s.size() && isdigit(s[i]))
           i++;
        
        }
        
        return i==s.size() && (interger || decimal);
    }
};