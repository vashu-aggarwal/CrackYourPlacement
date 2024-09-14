class Solution {
public:
    bool isCycle(int i,vector<vector<int>>& graph,vector<bool>& vis,vector<bool>& parent){
        vis[i]=true;
        parent[i]=true;

        for(int &v:graph[i]){
            if(vis[v]==false && isCycle(v,graph,vis,parent))
               return true;
            else if(parent[v]==true)
               return true;
        }

        parent[i]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<bool> vis(v,0);
        vector<bool> parent(v,0);
        vector<int> safe;
        for(int i=0;i<v;i++){
            if(!vis[i])
               isCycle(i,graph,vis,parent);
        }

        for(int i=0;i<v;i++){
            if(parent[i]==false){
                safe.push_back(i);
            }
            
        }

        return safe;
    }
};