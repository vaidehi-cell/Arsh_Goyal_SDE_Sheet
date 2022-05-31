class Solution {
    private:
    void visit(vector<vector<char>> &grid, int i, int j, int &n, int &m)
    {
        if(!(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0'))
        {
            grid[i][j] = '0';
            visit(grid, i-1, j, n, m); 
            visit(grid, i, j-1, n, m);
            visit(grid, i+1, j, n, m);
            visit(grid, i, j+1, n, m);
        }
    }
    public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    visit(grid, i, j, n, m);
                }                   
            }
        }
        return ans;
    }
};
