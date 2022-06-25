class Solution {
public:
    void visit(vector<vector<int>> &grid, int i, int j, int &n, int &m, vector<pair<int, int>> &island)
    {
        if(!(i < 0 || j < 0 || i > n-1 || j > m-1 || grid[i][j] == 0))
        {
            grid[i][j] = 0;
            island.push_back({i, j});
            visit(grid, i-1, j, m, n, island);
            visit(grid, i, j-1, m, n, island);
            visit(grid, i+1, j, m, n, island);
            visit(grid, i, j+1, m, n, island);
        }
    }
    int shortestDist(vector<pair<int, int>> i1, vector<pair<int, int>> i2)
    {
        int res = INT_MAX;
        for(int i = 0; i < i1.size(); i++)
        {
            for(int j = 0; j < i2.size(); j++)
            {
                int dist = abs(i1[i].first-i2[j].first);
                dist += abs(i1[i].second-i2[j].second);
                res = min(dist, res);
            }
        }
        return res;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int, int>> i1, i2;
        int n = grid.size(), m = grid[0].size(), x = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 && x == 0)
                {
                    visit(grid, i, j, m, n, i1);
                    x = 1;
                }
                else if(grid[i][j] == 1 && x == 1)
                    visit(grid, i, j, m, n, i2);
            }
        }
        int ans = shortestDist(i1, i2)-1;
        return ans;
    }
};
