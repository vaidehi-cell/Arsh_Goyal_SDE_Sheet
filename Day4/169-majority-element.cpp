class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> count;
        for(int i = 0; i < nums.size(); i++)
            count[nums[i]]++;
        for(auto x: count)
            if(x.second > nums.size()/2)
                return x.first;
        return 0;
    }
};
