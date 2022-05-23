class Solution {
public:
     bool foundWord(vector<vector<char>> &board, string word, int i, int j, int k)
     {
        if(k == word.size()) 
            return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[k]) 
            return false;
        bool ans = false;
        board[i][j] = '#';
        ans = foundWord(board, word, i+1, j, k+1) || foundWord(board, word, i-1, j, k+1) || foundWord(board, word, i, j+1, k+1) || foundWord(board, word, i, j-1, k+1);
        board[i][j] = word[k]; 
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        for(int i = 0; i < board.size(); i++) 
        {
            for(int j = 0; j < board[i].size(); j++) 
            {
                if(foundWord(board, word, i, j, 0)) 
                    return true;
            }
        }
        return false;
    }
};
