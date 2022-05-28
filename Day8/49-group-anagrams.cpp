class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> ans;
        vector<pair<string, string>> strs1;
        
        for(int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(strs[i].begin(), strs[i].end());
            strs1.push_back({strs[i], s});
        }
        sort(strs1.begin(), strs1.end());
        
        ans.push_back({strs1[0].second});
        for(int i = 1; i < strs1.size(); i++)
        {
            if(strs1[i].first == strs1[i-1].first)
                ans.back().push_back(strs1[i].second);
            else
                ans.push_back({strs1[i].second});
        }
        return ans;
    }
};
