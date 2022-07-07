class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        int dp[m+1][n+1];
        for(int i = 0; i <= m; i++)
            for(int j = 0; j <= n; j++)
                dp[i][j] = 0;
        for(int i = 0; i < strs.size(); i++)
        {
            int z = 0, o = 0;
            for(int j = 0; j < strs[i].size(); j++)
            {
                if(strs[i][j] == '0')
                    z++;
            }
            o = strs[i].size() - z;
            for(int j = m; j >= z; j--) 
                for(int k = n; k >= o; k--) 
                    dp[j][k] = max(dp[j][k], 1 + dp[j - z][k - o]);
        }
     return dp[m][n];   
    }
};
