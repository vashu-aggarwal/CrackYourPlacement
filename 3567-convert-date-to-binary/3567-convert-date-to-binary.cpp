class Solution {
public:
    string convertDateToBinary(string date) {
        string temp="";
        string ans="";
        for(int i=0;i<date.size();i++){
            temp="";
            while(i<date.size() && date[i]!='-'){
                temp.push_back(date[i]);
                i++;
            }

            int number=stoi(temp);
            string binary="";
            while(number>0){
                int a =number%2;
                binary=to_string(a)+binary;
                number=number/2;
            }
            ans+=binary;
            if(i<date.size()){

            ans+=date[i];
            }
            
        }

        return ans;
    }
};