class Solution {
public:
   map<int, string> words;
    bool allzero(string s)
    {
        for(int i = 0; i < s.size(); i++)
            if(s[i] != '0')
                return false;
        return true;
    }
    string part(string s)
    {
        string res = "";
        if(allzero(s))
            return res;   
        if(s.size() == 3)
        {
            if(s[0] != '0')
                res += words[s[0]-'0'] + " Hundred";
            if(res.size() > 0 && s[1] != '0')
                res += " ";
            if(s[1] == '1')
            {
                res += words[stoi(s.substr(1, 2))];
                return res;
            }
            if(s[1] != '0')
                res += words[(s[1]-'0')*10];  
            if(res.size() > 0 && s[2] != '0')
                res += " "; 
            if(s[2] != '0')
                res += words[s[2]-'0'];
        }
        else if(s.size() == 2 && s[0] > '1' && s[1] > '0')
            res += words[(s[0]-'0')*10] + " " + words[s[1]-'0'];
        else if(s.size() == 2 && (s[0] == '1' || s[1] == '0'))
            res += words[stoi(s)];
        else if(s.size() == 2 && s[0] == '0')
            res += words[s[1]-'0'];
        else if(s.size() == 1)
            res += words[s[0]-'0'];
        return res;
    }
    string numberToWords(int num) {
        words[0] = "Zero";
        words[1] = "One";
        words[2] = "Two";
        words[3] = "Three";
        words[4] = "Four";
        words[5] = "Five";
        words[6] = "Six";
        words[7] = "Seven";
        words[8] = "Eight";
        words[9] = "Nine";
        words[10] = "Ten";
        words[11] = "Eleven";
        words[12] = "Twelve";
        words[13] = "Thirteen";
        words[14] = "Fourteen";
        words[15] = "Fifteen";
        words[16] = "Sixteen";
        words[17] = "Seventeen";
        words[18] = "Eighteen";
        words[19] = "Nineteen";
        words[20] = "Twenty";
        words[30] = "Thirty";
        words[40] = "Forty";
        words[50] = "Fifty";
        words[60] = "Sixty";
        words[70] = "Seventy";
        words[80] = "Eighty";
        words[90] = "Ninety";
        string s = to_string(num);
        if(num == 0)
            return words[0];
        if(s.size() <= 3)
            return part(s);
        else
        {
            int p = s.size() / 3 + s.size() % 3 ? 1 : 0;
            string ans = "";
            int p1 = 0, p2 = 0, p3 = 0, p4 = 0; 
            p4 = min(3, (int)s.size());
            p3 = min(3, (int)s.size() - p4);
            p2 = min(3, (int)s.size() - p4 - p3);
            p1 = min(3, (int)s.size() - p4 - p3 - p2);
            if(p1 > 0)
            {
                string sp = s.substr(0, p1);
                ans += part(sp);
                ans += " Billion";
            }
            if(p2 > 0)
            {
                string sp = part(s.substr(p1, p2));
                if(ans.size() > 0 && sp.size() > 0)
                    ans += " " + sp + " Million"; 
                else if(sp.size() > 0)
                    ans += sp + " Million";
            }
            if(p3 > 0)
            {
                string sp = part(s.substr(p1 + p2, p3));
                if(ans.size() > 0 && sp.size() > 0)
                    ans += " " + sp + " Thousand"; 
                else if(sp.size() > 0)
                    ans += sp + " Thousand";
            }
            if(p4 > 0)
            {
                string sp = part(s.substr(p1 + p2 + p3, p4));
                if(ans.size() > 0 && sp.size() > 0)
                    ans += " " + sp; 
                else if(sp.size() > 0)
                    ans += sp;
            }
            return ans;
        }
    }
};
