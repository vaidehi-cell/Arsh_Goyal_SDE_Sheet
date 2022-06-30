class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
         vector<pair<int,int>> graph[n];
        for(auto x : flights)
            graph[x[0]].push_back({x[1], x[2]});
        
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        pq.push({0, src, -1});
        set<string> vis;
        while(!pq.empty())
        {
            vector<int> cur = pq.top();
            pq.pop();
            int weight = cur[0], node = cur[1], stops = cur[2];
            string hash = to_string(node) + "_" + to_string(stops);
            if(vis.find(hash) != vis.end())
                continue;
            if(node == dst)
                return weight;
            vis.insert(hash);
            if(stops + 1 <= k)
            {
                for(auto cnode : graph[node])
                {
                    int node1 = cnode.first;
                    int weight1 = cnode.second;
                    string newhash = to_string(node1) + "_" + to_string(stops + 1);
                    if(vis.find(newhash) == vis.end())
                        pq.push({weight + weight1, node1, stops + 1});
                }
            }
        }
        return -1;
    }
};
