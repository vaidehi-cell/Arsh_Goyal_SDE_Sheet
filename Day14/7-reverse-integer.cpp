class Solution {
public:
    int reverse(int x) 
    {
        int j = 1;
        if(x < 0)
        {
            j = 0;
            if(x == INT_MIN)
                return 0;
            x = -x;
        }
        long long ans = 0;
        while(x)
        {
            if(ans > INT_MAX || ans < INT_MIN)
                return 0;
            ans *= 10;
            ans += x % 10;
            if(ans > INT_MAX || ans < INT_MIN)
                return 0;
            x /= 10;
        }
        if(j == 0)
            ans = -ans;
        return (int)ans;
    }
};
