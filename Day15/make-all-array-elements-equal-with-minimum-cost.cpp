int solve(vector<int> arr, int n)
{
    int minCost = 0, mean;
    if(n % 2)
    {
        mean = arr[n / 2];
        for(int i = 0; i < n; i++)
            minCost += abs(arr[i] - mean);
        return minCost;
    }
    else
    {
        int minCost1 = 0;
        mean = arr[n / 2] + arr[n / 2 + 1];
        mean /= 2;
        for(int i = 0; i < n; i++)
            minCost += abs(arr[i] - mean);
        mean++;
        for(int i = 0; i < n; i++)
            minCost1 += abs(arr[i] - mean);
        return min(minCost, minCost1);
    }
}
