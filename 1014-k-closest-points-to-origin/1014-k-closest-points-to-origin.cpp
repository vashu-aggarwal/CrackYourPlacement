class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        typedef pair<double,vector<int>> pv;
        priority_queue<pv,vector<pv>,greater<pv>> pq;

        for(int i=0;i<points.size();i++){
            double t=sqrt(pow(points[i][0],2)+pow(points[i][1],2));
            pq.push({t,points[i]});
        }

        while(k--){
            pv top=pq.top();
            pq.pop();

            ans.push_back(top.second);
        }
        return ans;
    }
};