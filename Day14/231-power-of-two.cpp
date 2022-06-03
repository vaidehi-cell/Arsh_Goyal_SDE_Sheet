class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if(n <= 0)
            return false;
        int x = (int)log2(n);
        if(n == 1 << x)
            return true;
        return false;
    }
};
