int solveCeiling(vector<int> arr, int low, int high, int x)
{
    if(x <= arr[low])
        return low;

    if(x > arr[high])
        return -1;

    int mid = low + (high - low) / 2;

    if(arr[mid] == x)
    {
        return mid;
    }
    if(arr[mid] < x)
    {
        if(mid + 1 <= high && arr[mid + 1] >= x)
            return mid + 1; 
        return solveCeiling(arr, mid + 1, high, x);
    }
    else
    {
        if(mid - 1 >= low && x > arr[mid - 1])
            return mid; 
        return solveCeiling(arr, low, mid - 1, x);
    }
}

int solveFloor(vector<int> arr, int low, int high, int x)
{
    int ceil = solveCeiling(arr, low, high, x);
    if(arr[ceil] == x)
        return ceil;
    else if(ceil > 0)
        return ceil - 1;
    else
        return -1;
}
