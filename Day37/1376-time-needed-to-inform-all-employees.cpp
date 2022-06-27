class Solution {
public:
    void recurse(int n, int cur, vector<int> &manager, vector<int>& informTime, int &sum)
    {
        if(manager[cur] != -1)
        {
            sum += informTime[manager[cur]];
            recurse(n, manager[cur], manager, informTime, sum);            
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        int ans = 0, sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum = 0;
            if(!informTime[i])
            {
                recurse(n, i, manager, informTime, sum);
                ans = max(sum, ans);
            }
        }
        return ans;
    }
};
