class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result="";
      int div;
      int rem;
      while(columnNumber>0)
      {
        rem=(columnNumber-1)%26;
        
        result.push_back(char(rem+'A'));
        
        columnNumber=(columnNumber-1)/26;
      }
      reverse(result.begin(),result.end());
      return result;
    }
};