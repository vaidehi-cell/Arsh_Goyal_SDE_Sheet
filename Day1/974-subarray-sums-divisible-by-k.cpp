class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        mp[0] = 1;
        int ans = 0, pre = 0;
        for(int i = 0; i < n; i++)
        {
            pre += nums[i];
            int rem = pre % k;   
            if(rem < 0) rem += k;    
            ans += mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};
