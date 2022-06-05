class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M > N)
            return -1;
        int low = 0, high = 0, res = INT_MAX;
        for(int i = 0; i < N; i++)
            high += A[i];
        while(low <= high)
        {
            int mid = low + (high - low) / 2, ans = 1, curr = 0;
            for(int i = 0; i < N; i++)
            {
                if(A[i] > mid)
                {
                    ans = M+1;
                    break;
                }
                if(curr + A[i] > mid)
                {
                    ans++;
                    curr = A[i];
                    if(ans > M)
                        break;
                }
                else
                    curr += A[i];
            }
            if(ans > M)
                low = mid + 1;
            else
            {
                high = mid - 1;
                res = mid;
            }
        }
        return res;
    }
};
