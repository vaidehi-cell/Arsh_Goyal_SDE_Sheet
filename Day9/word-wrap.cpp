class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size();
        int extras[n+1][n+1];
        int lc[n+1][n+1];
        int c[n+1];
        int i, j;
        for(int i = 1; i <= n; i++)
        {
            extras[i][i] = k - nums[i-1];
            for (j = i + 1; j <= n; j++)
                extras[i][j] = extras[i][j-1] - nums[j-1] - 1;
        }
        for (i = 1; i <= n; i++)
        {
            for (j = i; j <= n; j++)
            {
                if (extras[i][j] < 0)
                    lc[i][j] = INT_MAX;
                else if (j == n && extras[i][j] >= 0)
                    lc[i][j] = 0;
                else
                    lc[i][j] = extras[i][j] * extras[i][j];
            }
        }
        c[0] = 0;
        for (j = 1; j <= n; j++)
        {
            c[j] = INT_MAX;
            for (i = 1; i <= j; i++)
            {
                if (c[i-1] != INT_MAX && lc[i][j] != INT_MAX && c[i-1] + lc[i][j] < c[j])
                    c[j] = c[i-1] + lc[i][j];
            }
        }
        return c[n];
    } 
};
