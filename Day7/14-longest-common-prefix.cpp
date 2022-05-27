class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string s = strs[0];
        for(int i = 1; i < strs.size(); i++)
        {
            int x = min(strs[i].size(), s.size());
            string s1 = "";
            for(int j = 0; j < x; j++)  
            {
                if(s[j] == strs[i][j])
                    s1 += s[j];
                else
                    break;
            }
            s = s1;
        }
        return s;
    }
};
