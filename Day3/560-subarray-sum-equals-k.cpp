class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size(), pre = 0, ans = 0;
        map<int, int> mp;
        mp[0] = 1;
        for(int i = 0; i < n; i++)
        {
            pre += nums[i];
            int rem = pre - k;
            if(mp.find(rem) != mp.end())
                ans += mp[rem];
            mp[pre]++;
        }
        return ans;
    }
};
