class Solution{
public:
    bool valid(vector<vector<char>> &mat, int i, int j, int n, int m)
    {
        if(i < n && j < m && i > -1 && j > -1 && mat[i][j] == 'O')
            return true;
        return false;
    }
    void dfs(int n, int m, int i, int j, vector<vector<char>> &mat)
    {
        if(valid(mat, i, j, n, m))
        {
            mat[i][j] = '#';
            dfs(n, m, i+1, j, mat);
            dfs(n, m, i-1, j, mat);
            dfs(n, m, i, j-1, mat);
            dfs(n, m, i, j+1, mat);
        }
        else 
            return;
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> &mat)
    {
        vector<vector<char>> ans(n, vector<char> (m));
        for(int i = 0; i < m; i++)
        {
            if(mat[0][i] == 'O')
                dfs(n, m, 0, i, mat);
        }
        for(int i = 1; i < n-1; i++)
        {
            if(mat[i][0] == 'O')
                dfs(n, m, i, 0, mat);
        }
        for(int i = 1; i < n-1; i++)
        {
            if(mat[i][m-1] == 'O')
                dfs(n, m, i, m-1, mat);
        }
        for(int i = 0; i < m; i++)
        {
            if(mat[n-1][i] == 'O')
                dfs(n, m, n-1, i, mat);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 'O')
                    ans[i][j] = 'X';
                else if(mat[i][j] == '#')
                    ans[i][j] = 'O';
                else
                    ans[i][j] = 'X';
            }
        }
        return ans;
    }
};
