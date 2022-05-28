class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        while(s[n-1] == ' ')
            n--;
        vector<string> words;
        words.push_back("");
        for(int i = 0; i < n; i++)
        {
            if(s[i] != ' ')
                words.back() += s[i];
            else if(words.size() > 0 && words.back() != "")
                words.push_back("");
        }
        string ans = "";
        for(int i = words.size()-1; i > -1; i--)
        {
            ans += words[i];
            if(i != 0)
                ans += ' ';
        }
        return ans;
    }
};
