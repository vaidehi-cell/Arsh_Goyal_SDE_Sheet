class Solution {
public:
    int liveNeighbours(vector<vector<int>> board, int i, int j)
    {
        int live = 0;
        if(i-1 > -1)
        {
            if(board[i-1][j] == 1)
                live++;
            if(j-1 > -1 && board[i-1][j-1] == 1)
                live++;
            if(j+1 < board[0].size() && board[i-1][j+1] == 1)
                live++;
        }
        if(i+1 < board.size())
        {
            if(board[i+1][j] == 1)
                live++;
            if(j-1 > -1 && board[i+1][j-1] == 1)
                live++;
            if(j+1 < board[0].size() && board[i+1][j+1] == 1)
                live++;
        }
        if(j > 0 && board[i][j-1] == 1)
            live++;
        if(j+1 < board[0].size() && board[i][j+1] == 1)
            live++;
        return live;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> next(n, vector<int>(m));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int live = liveNeighbours(board, i, j);
                if(board[i][j] && live < 2)
                    next[i][j] = 0;
                else if(board[i][j] && (live == 2 || live == 3))
                    next[i][j] = 1;
                else if(board[i][j])
                    next[i][j] = 0;
                else if(!board[i][j] && live == 3)
                    next[i][j] = 1;
                else
                    next[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                board[i][j] = next[i][j];
        }
    }
};
