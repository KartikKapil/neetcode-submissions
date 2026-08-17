class Solution {
public:
    vector<vector<string>> ans;
    
    bool check_board(vector<string> board,int i,int j,int n)
    {
        for(int k=i+1;k<n;k++)
        {
            if(board[k][j]=='Q')
                return false;
        }
        for(int k=i-1;k>=0;k--)
        {
            if(board[k][j]=='Q')
                return false;
        }
        for(int x=i+1,y=j+1;x<n and y<n;x++,y++)
        {
            if(board[x][y]=='Q')
                return false;
        }
        for(int x=i-1,y=j-1;x>=0 and y>=0;x--,y--)
        {
            if(board[x][y]=='Q')
                return false;
        }
        for(int x=i-1,y=j+1;x>=0 and y<n;x--,y++)
        {
            if(board[x][y]=='Q')
                return false;
        }
        for(int x=i+1,y=j-1;x<n and y>=0;x++,y--)
        {
            if(board[x][y]=='Q')
                return false;
        }
        
        return true;
        
    }
    void helper(int i,vector<string> &board,int n)
    {
        if(i>=n)
        {
            ans.push_back(board);
            return ;
        }
        for(int j=0;j<n;j++)
        {
            if(board[i][j]=='.')
            {
                if(check_board(board,i,j,n))
                {
                    board[i][j]='Q';
                    helper(i+1,board,n);
                    board[i][j]='.';
                }
            }
        }
        return ;
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board;
        
        string st = "";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                st.push_back('.');
            }
            board.push_back(st);
            st = "";
        }
        
        int i=0;
        int j=0;
        
        helper(i,board,n);
        
        return ans;
    }
};