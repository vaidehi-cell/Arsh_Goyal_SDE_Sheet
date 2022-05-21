class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.size()==0)
            return 0;
        int i = 0, k = 0;
        nums[k] = nums[i];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != nums[k])
            {
                k++;
                nums[k] = nums[i];
            }
        }
        return k+1;
    }
};
