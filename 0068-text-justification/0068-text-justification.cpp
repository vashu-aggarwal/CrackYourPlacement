class Solution {
public:
    string findLine(int i,int j,int eachspace,int extreaspace,vector<string>& words,int maxWidth){
        string line;
        for(int k=i;k<j;k++){
            line+=words[k];


            if(k==j-1) continue; //last word of every line no space
            for(int z=1;z<=eachspace;z++){
                line+=" ";
            }
            if(extreaspace>0){
                line+=" ";
                extreaspace--;
            }
        }
            while(line.length()<maxWidth){
                line+=" ";
            }
            return line;
        }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i=0;
        vector<string> ans;
        while(i<words.size()){
            int lettercount=words[i].length();
            int spaces=0;
            int j=i+1;
            while(j<words.size() && words[j].length()+1+spaces+lettercount<=maxWidth){
                lettercount+=words[j].length();
                spaces++;
                j++;
            }

            int remaningspace=maxWidth-lettercount;//kite space hamre pass hai
            int eachspace=spaces==0? 0: remaningspace/spaces;// kite space dalane hai har word ke beech
            int extreaspace=spaces==0? 0: remaningspace%spaces;// kite extra space dalenge 

            if(j==words.size()){
               eachspace=1;
               extreaspace=0;
            }
            ans.push_back(findLine(i,j,eachspace,extreaspace,words,maxWidth));
            i=j;
        }

        return ans;
    }
};