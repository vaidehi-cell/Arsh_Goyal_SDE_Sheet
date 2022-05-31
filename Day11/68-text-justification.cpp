class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        for (int i = 0, j = 0; i < words.size(); j = ++i)
        {            
            int currsize = 0;
            while (i < words.size() && currsize + words[i].size() + i - j <= maxWidth)
            {
                currsize += words[i].size();
                i++;
            }
            i--;
            string line;
            int spaces = maxWidth - currsize;
			      int tspace = (i == j || i == words.size() - 1) ? 1 : spaces / (i - j); 
			      int extra = (i == j || i == words.size() - 1) ? 0 : spaces % (i - j);
            while (j <= i)
            {
                if (!line.empty())
                {
                    line += string(tspace, ' ');
                    spaces -= tspace;
                    if(extra) 
                    {
                        line += ' ';
                        extra--;
                        spaces--;
                    }
                }
                line += words[j];
                j++;
            }
            line += string(spaces, ' ');
            ans.push_back(line);
        }
        return ans;
    }
};
