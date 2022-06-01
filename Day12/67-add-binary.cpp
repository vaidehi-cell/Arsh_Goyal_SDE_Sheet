class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int r = 0;
        for(int i = 0; i < min(a.size(), b.size()); i++)
        {
            ans += '0'+((a[i]-'0')+(b[i]-'0')+r)%2;
            r = (a[i]-'0')+(b[i]-'0')+r > 1 ? 1 : 0;
        }
        int j = min(a.size(), b.size());
        while(j < a.size())
        {
            ans += '0'+((a[j]-'0')+r)%2;
            r = (a[j]-'0')+r > 1 ? 1 : 0;
            j++;
        }
        while(j < b.size())
        {
            ans += '0'+((b[j]-'0')+r)%2;
            r = (b[j]-'0')+r > 1 ? 1 : 0;
            j++;
        }
        if(r > 0)
            ans += '0'+r;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
