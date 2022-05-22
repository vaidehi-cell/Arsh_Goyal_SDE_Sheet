class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) 
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++)
        {
            if( i > 0 && nums[i] == nums[i-1])
                continue;
               int j = i + 1, k = n - 1;
            while(j < k)
            {
			    int sum = nums[i] + nums[j] + nums[k];
			    if(sum == 0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    k--;
                    while(j < k && nums[k] == nums[k+1]) 
                        k--;
                } 
                else if(sum > 0) k--;
                else j++;
			}
        }
        return ans;
    }
};
