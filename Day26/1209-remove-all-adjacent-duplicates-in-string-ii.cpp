class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        if(s.size() < k)
            return s;
        stack<pair<char, int>> ss;
        for(int i = 0; i < s.size(); i++)
        {
            if(ss.empty() || ss.top().first != s[i])
                ss.push({s[i], 1});
            else
            {
                pair<char, int> tp = ss.top();
                ss.pop();
                ss.push({s[i], tp.second + 1});
            }
            if(ss.top().second == k)
                ss.pop();
        }
        string ans = "";
        while(!ss.empty())
        {
            int x = ss.top().second;
            x = x % k;
            while(x--)
                ans += ss.top().first;
            ss.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
