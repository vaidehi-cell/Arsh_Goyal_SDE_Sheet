vector<ll> nextGreaterElementLeft(ll n, vector<ll> arr)
{
    stack<ll> s;
    vector<ll> left(n + 1);
    for(ll i = 0; i < n; i++)
        left[i] = -1;
    for (ll i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if (!s.empty())
            left[i] = s.top();
        s.push(i);
    }
    return left;
}
vector<ll> nextGreaterElementRight(ll n, vector<ll> arr)
{
    stack<ll> s;
    vector<ll> right(n + 1);
    for(ll i = 0; i < n; i++)
        right[i] = n;
    for(ll i = n - 1 ; i >= 0 ; i--)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if(!s.empty())
            right[i] = s.top();
        s.push(i);
    }
    return right;
}

vector<int> solve(ll n, vector<ll> a)
{
    vector<ll> left = nextGreaterElementLeft(n, a);
    vector<ll> right = nextGreaterElementRight(n, a);
    vector<ll> ans(n + 1, 0ll);
    for(ll i = 0; i < n; i++)
    {
        ll len = right[i] - left[i] - 1;
        ans[len] = max(ans[len], a[i]);
    }
    for(ll i = n - 1; i >= 1; i--)
        ans[i] = max(ans[i], ans[i + 1]);
    return (ans);
}
