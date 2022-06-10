class Solution {
public:
    bool isPossible(int mid, vector<int> nums, int m)
    {
        int sum = 0, size = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(sum + nums[i] <= mid)
                sum += nums[i];
            else
            {
                sum = nums[i];
                size++;
            }
        }
        if(size <= m)
            return true;
        return false;
    }
    int splitArray(vector<int>& nums, int m) 
    {
        int mx = 0, sum = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            mx = max(mx, nums[i]);
            sum += nums[i];
        }
        int l = mx, r = sum;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(isPossible(mid, nums, m))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};
