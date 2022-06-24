class Solution {
public:
    string decodeString(string s) 
    {
        if(!s.size())
            return s;
        string ans = "";
        stack<string> sub;
        stack<int> st;
        int num = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] <= '9' && s[i] >= '0')
                num = num * 10 + s[i]-'0';
            else if(s[i] >= 'a' && s[i] <= 'z')
                ans += s[i];
            else if(s[i] == '[')
            {
                sub.push(ans);
                st.push(num);
                ans = "";
                num = 0;
            }
            else
            {
                string tp = ans;
                for(int i = 1; i < st.top(); i++)
                    ans += tp;
                ans = sub.top() + ans;
                st.pop();
                sub.pop();
            }
        }
        return ans;
    }
};
