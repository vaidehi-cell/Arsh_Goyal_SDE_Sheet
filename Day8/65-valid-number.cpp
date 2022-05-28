class Solution {
public:
    bool isDec(string s)
    {
        if(s.size() == 0)
            return false;
        int i = s[0] == '+' || s[0] == '-' ? 1 : 0;
        if(s[i] == '.')
        {
            if(i+1 == s.size())
                return false;
            i++;
            while(i < s.size() && s[i] >= '0' && s[i] <= '9')
                i++;
            if(i == s.size())
                return true;
            return false;
        }
        else
        {
            if(s[i] > '9' || s[i] < '0')
                return false;
            while(i < s.size() && s[i] >= '0' && s[i] <= '9')
                i++;
            if(i == s.size())
                return true;
            else if(s[i] != '.')
                return false;
            i++;
             while(i < s.size() && s[i] >= '0' && s[i] <= '9')
                i++;
            if(i == s.size())
                return true;
            return false;
        }
    }
    
    bool isInt(string s)
    {
        if(s.size() == 0)
            return false;
        int i = 0;
        if(s[0] == '+' || s[0] == '-')
            i++;
        while(i < s.size() && s[i] >= '0' && s[i] <= '9')
            i++;
        if((s[0] == '+' || s[0] == '-') && s.size() == 1)
            return false;
        if(i == s.size())
            return true;
        return false;
    }
    
    bool isNumber(string s) {
        int e = 0;
        string s1 = "", s2 = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(e == 1)
                s2 += s[i];
            if(s[i] == 'e' || s[i] == 'E')
                e++;
            if(e == 0)
                s1 += s[i];
            if(e > 1)
                return false;
        }
        if(s2.size() > 0)
        {
            return (isDec(s1) || isInt(s1)) && isInt(s2);
        }
        else
        {
            if(e == 0)
                return isDec(s1) || isInt(s1);
            else
                return false;
        }
        return false;
    }
};
