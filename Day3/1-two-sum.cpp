class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        int k = 0, idx = -1;
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = i+1;
            if(nums[i] * 2 == target && k == 0)
                k++, idx = i;
            else if(nums[i] * 2 == target && k == 1)
            {
                ans.push_back(idx);
                ans.push_back(i);
                return ans;
            }
        }
        for(auto x: mp)
        {
            if(2 * x.first != target && mp.find(target-x.first) != mp.end() && mp[target-x.first] > 0)
            {
                ans.push_back(x.second - 1);
                ans.push_back(mp[target - x.first]-1);
                return ans;
            }
        }
        return ans;
    }
};
