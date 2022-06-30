class Solution {
public:
    bool isValid(int i, int j, int n)
    {
        if(i >= 0 && j >= 0 && i < n && j < n)
            return true;
        return false;
    }
    
    int getArea(vector<vector<int>>& grid, int i, int j, int group, int n)
    {
        if(i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1)
            return 0;
        grid[i][j] = group;
        return 1 + getArea(grid, i + 1, j, group, n) + getArea(grid, i, j - 1, group, n) + getArea(grid, i, j + 1, group, n) + getArea(grid, i - 1, j, group, n);
    }
    
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size(), group = 2;
        map<int, int> area;
        bool f = false;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    area[group] = getArea(grid, i, j, group, n);
                    group++;
                    f = true;
                }
            }
        }
        if(!f)
        return 1;
        int ans = area[2];
        vector<vector<int>> dir(4);
        dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0)
                {
                    set<int> st;
                    int curr = 1;
                    for(auto d : dir)
                    {
                        int x1 = i + d[0], y1 = j + d[1];
                        if(isValid(x1, y1, n))
                        {
                            int id = grid[x1][y1];
                            if(st.find(id) == st.end())
                            {
                                curr += area[id];
                                st.insert(id);
                            }
                        }
                    }
                    ans = max(ans, curr);
                }
            }
        }
        if(ans == 0)
            return n*n;
        return ans;
    }
};
