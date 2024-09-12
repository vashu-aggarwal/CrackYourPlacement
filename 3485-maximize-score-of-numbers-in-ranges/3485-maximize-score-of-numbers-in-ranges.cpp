class Solution {
public:
    bool check(int m,vector<int>& start, int d){
         int s=start[0];
         int e=start[0]+d;

         for(int i=1;i<start.size();i++){
            int ns=start[i];
            int ne=start[i]+d;

            if((ne-s)<m){
                return false;
            }

            s=max(s+m,ns);
            e=ne;
         }

         return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(),start.end());

        int s=0;
        int e=(start[start.size()-1]+d)-start[0];
        int ans=0;

        while(s<=e){
            int m=s+(e-s)/2;

            if(check(m,start,d)){
                ans=m;
                s=m+1;
            }
            else{
                e=m-1;
            }
        }
        return ans;
    }
};