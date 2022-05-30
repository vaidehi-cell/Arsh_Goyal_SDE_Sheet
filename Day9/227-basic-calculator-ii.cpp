class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int curr = 0, ans = 0;
        char op = '+';
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
                curr = curr * 10 + (s[i] - '0');
            if((s[i] != ' ' && s[i] != '\t' && !isdigit(s[i])) || i == s.size()-1)
            {
                if(op == '-')
                    st.push(-curr);
                else if(op == '+')
                    st.push(curr);
                else if(op == '*')
                {
                    int tp = st.top();
                    st.pop();
                    st.push(tp * curr);
                }
                else if(op == '/')
                {
                    int tp = st.top();
                    st.pop();
                    st.push(tp / curr);
                }
                op = s[i];
                curr = 0;
            }
        }
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
