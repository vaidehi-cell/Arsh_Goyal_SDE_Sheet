class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 1)
            return 1;
        double inf = numeric_limits<double>::max();
        map<pair<double, double>, set<pair<int, int>>> lines;
        map<int, set<int>> hor, ver;
        for(int i = 0; i < points.size(); i++)
        {
            for(int j = i + 1; j < points.size(); j++)
            {
                if(points[i][0] == points[j][0])
                {
                    ver[points[i][0]].insert(points[i][1]);
                    ver[points[i][0]].insert(points[j][1]);
                }
                else if(points[i][1] == points[j][1])
                {
                    hor[points[i][1]].insert(points[i][0]);
                    hor[points[i][1]].insert(points[j][0]);
                }
                else
                {
                    double m = (double)(points[j][1] - points[i][1])/(double)(points[j][0] - points[i][0]);
                    double c = points[i][1] - (points[i][0] * m);
                    lines[{m, c}].insert({points[i][0], points[i][1]});
                    lines[{m, c}].insert({points[j][0], points[j][1]});
                }
            }
        }
        int ans = 0;
        for(auto x: lines)
            ans = max(ans, (int)x.second.size());
        for(auto x: ver)
           ans = max(ans, (int)x.second.size());
        for(auto x: hor)
            ans = max(ans, (int)x.second.size());
        return ans;
    }
};
