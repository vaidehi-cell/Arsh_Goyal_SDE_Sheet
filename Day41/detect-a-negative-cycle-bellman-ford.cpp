class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges)
	{
	    vector<int> dist(n, INT_MAX);
	    dist[0] = 0;
	    for(int i = 0; i < n-1; i++)
	    {
	        for(int j = 0; j < edges.size(); j++)
	        {
	            int u = edges[j][0], v = edges[j][1], w = edges[j][2];
	            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
	        }
	    }
	    for (int i = 0; i < edges.size(); i++) 
	    {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                return 1;
        }
        return 0;
	}
};
