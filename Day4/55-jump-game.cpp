class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool flag = false;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == 0)
                flag = true;
        if(!flag)
            return true;
        else
        {
            int target = nums.size() - 1;
            for(int i = nums.size() - 2; i > -1; i--)
            {
                if(i + nums[i] >= target)
                    target = i;
            }
            if(target)
                return false;
            else
                return true;
        }
    }
};
