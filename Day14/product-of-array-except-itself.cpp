void solve(ll n, vector<int> arr)
{
    vector<int> pre(n + 1), post(n + 1);   
    pre[0] = 1, post[n] = 1;

    for(int i = 0; i < n; i++)
        pre[i+1] = pre[i] * arr[i];
    for(int i = n; i > 0; i--)
        post[i-1] = post[i] * arr[i-1];
    
    vector<int> ans(n);
    for(int i = 0; i < n; i++)
        ans[i] = pre[i] * post[i+1];
    
    cout << "The product array is:\n";
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
}
