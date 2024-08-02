class NumMatrix {
public:
    vector<vector<int>> matrix1;
    int n=0,m=0;
    NumMatrix(vector<vector<int>>& matrix) {
        matrix1=matrix;
        n=matrix1.size();
        m=matrix1[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                matrix1[i][j]=matrix1[i][j]+matrix1[i][j-1];
                
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1;i<=row2;i++){
            if(col1-1>=0){
                int element=matrix1[i][col2]-matrix1[i][col1-1];
                
                sum+=element;
            }
            else
              sum+=matrix1[i][col2];
        }

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */