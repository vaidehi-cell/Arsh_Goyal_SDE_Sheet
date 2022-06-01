class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int prod = nums[n-1] * nums[n-2] * nums[n-3];
        prod = max(prod, nums[0] * nums[1] * nums[n-1]);
        return prod;
    }
};
