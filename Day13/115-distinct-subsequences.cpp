class Solution {
public:
    map<pair<int, int>, int> mem;
    int ways(string s, string t, int sstart, int tstart)
    {
        if(s.size() - sstart < t.size() - tstart)
            return 0;
        if(tstart == t.size())
            return 1;
        if(mem.find({sstart, tstart}) == mem.end())
        {
            if(s[sstart] != t[tstart])
                return ways(s, t, sstart + 1, tstart);
            else
            {
                int ans = ways(s, t, sstart + 1, tstart + 1) + ways(s, t, sstart + 1, tstart);
                mem[{sstart, tstart}] = ans;
                return ans;
            }
        }
        return mem[{sstart, tstart}];
    }
    int numDistinct(string s, string t) 
    {
        return ways(s, t, 0, 0);        
    }
};
