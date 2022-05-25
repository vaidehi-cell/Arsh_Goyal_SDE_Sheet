class Solution {
public:
    int merge(vector<int> &nums, int l, int mid, int r)
    {  
        int size1 = mid - l + 1, size2 = r - mid;
        int A[size1], B[size2];
        for(int i = 0; i < size1; i++)
            A[i] = nums[l + i];
        for(int i = 0; i < size2; i++)
            B[i] = nums[mid + 1 + i];
        
        int revs = 0, i = 0, j = 0;
        for(i = 0; i < size1; i++) //main inversion count logic time O(n+m) =>O(N)
        {
            while(j < size2 && (double(A[i]) / 2) > double(B[j]))
                j++;
            revs += j; 
        }
        
        i = 0, j = 0;
        int k = l;
        while(i < size1 && j < size2)
        {   
            if(A[i] < B[j])
                nums[k] = A[i], i++;
            else
                nums[k] = B[j], j++;
            k++;
        }
        while(j < size2)
            nums[k++] = B[j++];
        while(i<size1)
            nums[k++] = A[i++];
        
        return revs;
    }
    
    int mergesort(vector <int>& nums, int l,int r)
    {   if(l < r)
        {
            int mid = l + (r - l)/2;
            int ans = mergesort(nums, l, mid);
            ans += mergesort(nums, mid + 1, r);
            ans += merge(nums, l, mid, r);
            return ans;
        }
        return 0;
    }
    
    int reversePairs(vector<int>& nums) 
    {
       return mergesort(nums,0,nums.size()-1);
    }    
};
