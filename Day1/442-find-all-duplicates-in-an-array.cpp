class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int> ans;
        map<int, int> count;
        for(int i = 0; i < nums.size(); i++)
            count[nums[i]]++;
        for(auto x: count)
            if(x.second > 1)
                ans.push_back(x.first);
        return ans;
    }
};
