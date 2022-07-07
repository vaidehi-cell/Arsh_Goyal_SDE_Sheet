class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
        priority_queue<int> pq;
        int ans = 0, fuel = startFuel, prev = 0;
        for(int i = 0; i < stations.size(); i++)
        {
            int loc = stations[i][0], cap = stations[i][1];
            fuel -= (loc - prev);
            while(!pq.empty() && fuel < 0)
            {
                fuel += pq.top();
                pq.pop();
                ans++;
            }
            if(fuel < 0)
                return -1;
            pq.push(cap);
            prev = loc;
        }
        fuel -= (target - prev);
        while(!pq.empty() && fuel < 0)
        {
            fuel += pq.top();
            pq.pop();
            ans++;
        }
        if(fuel < 0)
            return -1;
        return ans;
    }
};
