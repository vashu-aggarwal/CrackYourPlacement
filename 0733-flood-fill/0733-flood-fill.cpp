class Solution {
public:
    void solve(vector<vector<int>>& image, int sr, int sc, int color,int original){
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size()){
            return;
        }
        if(image[sr][sc]!=original){
            return;
        }
        image[sr][sc]=color;
        solve(image,sr-1,sc,color,original);
        solve(image,sr+1,sc,color,original);
        solve(image,sr,sc-1,color,original);
        solve(image,sr,sc+1,color,original);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original=image[sr][sc];
        if(original!=color)
            solve(image,sr,sc,color,original);
         return image;
    }
};