class Solution {
public:
    bool helper(vector<vector<char>>& board,string word,int i,int j,int k)
    {
         if(k==word.size())
          return true;
         if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || word[k]!=board[i][j])
           return false;
        
        char ch=board[i][j];
        board[i][j]=' ';

        bool down=helper(board, word, i + 1, j, k + 1);
        bool right=helper(board, word, i, j + 1, k + 1);
        bool up=helper(board, word, i - 1, j, k + 1);
        bool left=helper(board, word, i, j - 1, k + 1);

        if(down || right || up || left)
        {
            return true;
        }

        board[i][j]=ch;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0]){
                   if(helper(board,word,i,j,0)) return true;
                }
            }
        }

        return false;
    }
};