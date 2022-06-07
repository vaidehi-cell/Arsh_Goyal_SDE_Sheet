bool isPossible(ll mid, ll n, ll c, vector<ll> &stalls)
{
    ll placed = 1, lastpos = stalls[0];
    for(ll i = 0; i < n; i++)
    {
        if(stalls[i] - lastpos >= mid)
        {
            placed++;
            if(placed == c)
                return true;
            lastpos = stalls[i];
        }
    }
    return false;
}

void solve(ll tc)
{
    ll n, c;
    cin >> n >> c;
    vector<ll> stalls(n);
    for(ll i = 0; i < n; i++)
        cin >> stalls[i];
    sort(stalls.begin(), stalls.end());
    ll low = 0, high = stalls[n-1], ans = 0;
    while(low <= high)
    {
        ll mid = low + (high - low) / 2;
        if(isPossible(mid, n, c, stalls))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << ans << endl;
}
