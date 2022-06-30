class Solution {
    vector<vector<int>> dirs = {{-1,0}, {0,-1}, {0,1}, {1,0}};
    
    int dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp, int prev) 
    {
        if(r < 0 || r >= matrix.size() || c < 0 || c >= matrix[r].size() || matrix[r][c]<= prev) 
            return 0;
        
        if(dp[r][c] != -1) 
            return dp[r][c];
        int ans = 0;
        for(auto &dir : dirs) 
        {
            int cur = dfs(matrix, dir[0] + r, dir[1]+c, dp, matrix[r][c]);
            ans = max(ans, cur);
        }
        return dp[r][c] = ans + 1;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        int ans = 0, curr;
        for(int i = 0; i < rows; i++) 
        {
            for(int j = 0; j < cols; j++) 
            {
                curr = dfs(matrix, i, j, dp, -1000000);
                ans = max(ans, curr);
            }
        }        
        return ans;
    }
};
