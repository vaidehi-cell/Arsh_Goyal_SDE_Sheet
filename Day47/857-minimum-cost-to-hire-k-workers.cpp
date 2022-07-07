class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, double>> v;
        
        for (int i = 0; i < wage.size(); i++) 
            v.push_back({double(wage[i]) / quality[i], quality[i]});

        sort(v.begin(), v.end());
        priority_queue<int> q;
        double ans = DBL_MAX, sum = 0;
        for (auto x : v) 
        {
            q.push(x.second);
            sum += x.second;

            if (q.size() > k) 
            {
                sum -= q.top();
                q.pop(); 
            }
            
            if (q.size() == k) 
                ans = min(ans, x.first * sum);
        }
        return ans;
    }
};
