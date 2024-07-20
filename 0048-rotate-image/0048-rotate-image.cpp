class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();

    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
            if(i!=j){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }

    for(int row=0;row<n;row++){
        int start=0;
        int end=n-1;

        while(start<end){
            swap(matrix[row][start],matrix[row][end]);
            start++;
            end--;
        }
    }
    }
};