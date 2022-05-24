class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i = m - 1, j = n - 1;
         while(i > -1 && j > -1)
            nums1[i + j + 2] = nums1[i] <= nums2[j] ? nums2[j--] : nums1[i--];
        if(i < 0)
            for(i = 0; i <= j; i++)
                nums1[i] = nums2[i];
    }
};
