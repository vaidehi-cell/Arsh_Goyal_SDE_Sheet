class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "", t1 = "";
        stack<char> ss;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '#' && ss.size())
                ss.pop();
            else if(s[i] != '#')
                ss.push(s[i]);
        }
        while(ss.size())
        {
            s1 += ss.top();
            ss.pop();
        }
        for(int i = 0; i < t.size(); i++)
        {
            if(t[i] == '#' && ss.size())
                ss.pop();
            else if(t[i] != '#')
                ss.push(t[i]);
        }
        while(ss.size())
        {
            t1 += ss.top();
            ss.pop();
        }
        if(s1.size() != t1.size())
            return false;
        for(int i = 0; i < s1.size(); i++)
        {
            if(s1[i] != t1[i])
                return false;
        }
        return true;
    }
};
