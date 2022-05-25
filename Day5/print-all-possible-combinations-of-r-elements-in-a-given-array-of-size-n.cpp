void printSol(vector<int> nums, vector<int> &pos)
{
    for (int i = 0; i < pos.size(); i++)
        cout << nums[pos[i]] << " ";
    cout << endl;
}

void permutations(vector<int> nums, vector<int> &pos, int l, int k, int r)
{
    if(k == r)
    {
        printSol(nums, pos);
        return;
    }
    for(int i = l; i < nums.size(); i++)
    {
        pos[k] = i;
        permutations(nums, pos, i + 1, k + 1, r);
        pos[k] = -1;
    }
}

//Driver function example:
/*
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int r = 3, n = 5; //n = number of elements in array, r = number of elements in permutation
    vector<int> pos(r, -1); // vector to hold position of numbers in current permutation
    Perms(nums, pos, 0, 0, n); //Calling the function
    return 0;
}
*/
