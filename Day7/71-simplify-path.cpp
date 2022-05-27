class Solution {
public:
    string simplifyPath(string path) 
    {
        stack<string> s;
        string res = "";
        vector<string> p;
        p.push_back("");
        for(int i = 0; i < path.size(); i++)
        {
            if(path[i] == '/')
                p.push_back("");
            else
                p.back() += path[i];
        }
        
        for(int i = 0; i < p.size(); i++)
        {
            if(!s.empty()  && p[i] == "..") 
                s.pop();
            else if(!(p[i] == "") && !(p[i] == ".") && !(p[i] == ".."))
                s.push(p[i]);
        }
        
        if(s.empty()) 
            return "/";
        vector<string> loc;
        while(!s.empty())
        {
            loc.push_back(s.top());
            s.pop();
        }
        for(int i = loc.size()-1; i > -1; i--)
        {
            res += '/';
            res += loc[i];
        }
        return res;
    }
};
