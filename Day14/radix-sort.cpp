vector<int> countSort(int n, vector<int> arr, int exp)
{   
    vector<int> output(n), count(10, 0);
    int i;

    for(int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for(i = 1; i < 10; i++)
        count[i] += count[i - 1];
    //out(count);
    for(int i = n-1; i > -1; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    return output;
}

vector<int> radixSort(ll n, vector<int> arr)
{
    int mx = *max_element(arr.begin(), arr.end());
    for(int i = 1; mx / i > 0; i *= 10)
        arr = countSort(n, arr, i);
    return arr;
}
