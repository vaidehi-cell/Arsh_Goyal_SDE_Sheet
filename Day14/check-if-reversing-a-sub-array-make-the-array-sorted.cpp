bool solve(ll n, vector<int> arr)
{
    int x = 1;
    while(x < n && arr[x] >= arr[x-1])
        x++;
    if(x == n)
        return true;

    int y = x;
    while(y < n && arr[y] < arr[y-1])
    {
        if(x > 1 && arr[y] < arr[x-2])
            return false;
        y++;
    }
    if(y == n)
        return true;

    int z = y;
    if(arr[z] < arr[x-1])
        return false;
    if(z > 1)
    {
        while(z < n)
        {
            if(arr[z] < arr[z-1])
                return false;
            z++;
        }
    }
    return true;
}
