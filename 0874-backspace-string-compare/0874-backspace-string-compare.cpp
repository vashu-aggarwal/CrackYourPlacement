class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;

        int i=0,j=0;
        while(i<s.length() && j<t.length()){
            if(s[i]!='#'){
                s1.push(s[i]);
            }
            else{
                if(!s1.empty())
                   s1.pop();
            }
            if(t[j]!='#'){
                s2.push(t[j]);
            }
            else{
                if(!s2.empty())
                   s2.pop();
            }
            i++;
            j++;
        }
        
        while(i<s.length()){
            if(s[i]!='#'){
                s1.push(s[i]);
            }
            else{
                if(!s1.empty())
                   s1.pop();
            }
            i++;
        }
        while(j<t.length()){
            if(t[j]!='#'){
                s2.push(t[j]);
            }
            else{
                if(!s2.empty())
                   s2.pop();
            }
            j++;
        }

        if(s1.size()!=s2.size()){
            return false;
        }
        else{
            string ans1="";
            string ans2="";
            while(!s1.empty()){
                ans1=s1.top()+ans1;
                s1.pop();
            }
            while(!s2.empty()){
                ans2=s2.top()+ans2;
                s2.pop();
            }
            
            return ans1==ans2;
        }
    }
};