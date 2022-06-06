//      size of array, array
int solve(ll n, vector<int> arr)
{
    int ans = 0;
    vector<pair<int, int>> actpos;
    for(int i = 0; i < n; i++)
        actpos.pb({arr[i], i});
    sort(actpos.begin(), actpos.end());

    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++)
    {
        if(!visited[i] && actpos[i].second != i)
        {
            int cycle = 0, j = i;
            while(!visited[j])
            {
                visited[j] = true;
                j = actpos[j].se;
                cycle++;
            }
            if(cycle)
                ans += cycle - 1;   
        }
    }
    return ans; // Minimum number of swaps required
}
