class Solution {
public:
    void generator(vector<string> &ans, string s, int l, int r, int size)
    {
        if(s.size() == 2*size)
        {
            ans.push_back(s);
            return;
        }
        if(l < size)
        {
            s += '(';
            generator(ans, s, l + 1, r, size);
            s = s.substr(0, s.length()-1);
        }
        if(r < l)
        {
            s += ')';
            generator(ans, s, l, r + 1, size);
            s = s.substr(0, s.length()-1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        generator(ans, s, 0, 0, n);
        return ans;
    }
};
