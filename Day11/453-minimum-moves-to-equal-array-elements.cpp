class Solution {
public:
    int minMoves(vector<int>& nums) 
    {
        int ans = 0, mn = nums[0];
        for(int i = 1; i < nums.size(); i++)
            mn = min(nums[i], mn);
        for(int i = 0; i < nums.size(); i++)
            ans += nums[i] - mn;
        return ans;
    }
};
