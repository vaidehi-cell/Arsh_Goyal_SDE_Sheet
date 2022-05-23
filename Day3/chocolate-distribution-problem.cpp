int distribution(vector<int> chocolates, int n, int m)
{
    if (m == 0 || n == 0)
        return 0;
    if (n < m)
        return -1;

    sort(all(chocolates));
    
    int ans = INT_MAX;

    for(int i = 0; i < n - m + 1; i++)
        ans = min(ans, chocolates[i+m-1]-chocolates[i]);

    return ans;
}
