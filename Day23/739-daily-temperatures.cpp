class Solution {
public:
    vector<int> nextGreaterElement(vector<int> arr)
    {
        vector<int> ans(arr.size(), -1);
        stack<pair<int,int>> s;
        s.push({arr[0], 0});
        for (int i = 1; i < arr.size(); i++)
        {
            if (s.empty()) 
            {
                s.push({arr[i], i});
                continue;
            }
            while (s.empty() == false && s.top().first < arr[i])
            {
                ans[s.top().second] = i;
                s.pop();
            }
            s.push({arr[i], i});
        }
        while(!s.empty()) 
        {
            ans[s.top().second] = -1;
            s.pop();
        }  
        return ans;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        vector<int> ans = nextGreaterElement(temperatures);
        for(int i = 0; i < temperatures.size(); i++)
        {
            if(ans[i] != -1)
                ans[i] = (ans[i] - i);
            else
                ans[i] = 0;
        }
        return ans;
    }
};
