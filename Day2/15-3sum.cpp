class Solution {
public:

    int min(int a, int b, int c)
    {
        if(a <= b && a <= c)
            return a;
        if(b <= a && b <= c)
            return b;
        return c;
    }

    int max(int a, int b, int c)
    {
        if(a >= b && a >= c)
            return a;
        if(b >= a && b >= c)
            return b;
        return c;
    }

    int mid(int a, int b, int c)
    {
        if((b >= a && b <= c) || ((b <= a && b >= c)))
            return b;
        if((a >= b && a <= c) || ((a <= b && a >= c)))
            return a;
        return c;
    }
    vector<vector<int>> threeSum(vector<int> &nums) 
    {
        set<vector<int>> ans;
        map<int, int> count;
        for(int i = 0; i < nums.size(); i++)
            count[nums[i]]++;
        for(auto x: count)
        {
            if(x.first == 0)
            {
                if(x.second >= 3)
                   ans.insert({0, 0, 0});
            }
            else
            {
                for(auto y: count)
                {
                    if(x.first == y.first && x.first != 0 && x.second > 1 && count.find(-2 * x.first) != count.end())
                        ans.insert({min(x.first, x.first, -2*x.first), mid(x.first, x.first, -2*x.first), max(x.first, x.first, -2*x.first)});                 
                    else if(x.first != y.first && x.first != -x.first-y.first && y.first != -x.first - y.first && count.find(-x.first - y.first) != count.end())
                        ans.insert({min(x.first, y.first, -y.first-x.first), mid(x.first, y.first, -y.first-x.first), max(x.first, y.first, -y.first-x.first)});
                }   
            }
        }
        int i = 0;
        vector<vector<int>> ans1(ans.size());
        for(auto x: ans)
        {
            for(auto y: x)
                ans1[i].push_back(y);
            i++;
        }
        return ans1;
    }
};
