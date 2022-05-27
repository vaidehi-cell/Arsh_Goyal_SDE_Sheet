class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        if(s.size() < p.size())
            return "-1";
        int start = -1, ans = INT_MAX, count = 0;
        map<char, int> m;
        for (int i = 0; i < p.size(); i++) 
        {
            if (m[p[i]] == 0)
                count++;
            m[p[i]]++;
        }
        int i = 0, j = 0;
        while(j < s.size())
        {
            m[s[j]]--;
            if(m[s[j]] == 0)
                count--;
            while (count == 0) 
            {
                if (ans > j - i + 1) 
                {
                    ans = min(ans, j - i + 1);
                    start = i;
                }
                m[s[i]]++;
                if (m[s[i]] > 0)
                    count++;
                i++;
            }
            j++;
        }
        if(start == -1)
            return "-1";
        return s.substr(start, ans);
    }
};
