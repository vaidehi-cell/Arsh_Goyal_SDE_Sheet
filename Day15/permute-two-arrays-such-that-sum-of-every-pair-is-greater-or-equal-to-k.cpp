bool cmp(ll a, ll b)
{
    return a > b;
}
bool solve(vector<int> a, vector<int> b, int n, int k)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), cmp);
    for(int i = 0; i < k; i++)
    {
        if(a[i] + b[i] < k)
            return false;
    }
    return true;
}
