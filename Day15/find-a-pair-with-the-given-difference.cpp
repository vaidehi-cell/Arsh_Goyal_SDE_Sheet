bool solve(vector<int> arr, int diff)
{
    if(arr.size() < 2)
        return false;
    unordered_map<int, int> count;
    for(int i = 0; i < arr.size(); i++)
    {
        if(count[arr[i] - diff] > 0 || count[arr[i] + diff] > 0)
            return true;
        count[arr[i]]++;
    }
    return false;
}
