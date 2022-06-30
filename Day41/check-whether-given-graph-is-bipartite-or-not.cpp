class Solution {
public:
    bool colorAll(vector<int>adj[], vector<int> &color, int par)
    {
        if(color[par] == -1)
            color[par] = 1;
        for(auto x: adj[par])
        {
            if(color[x] == -1)
            {
                color[x] = 1-color[par];
                if(!colorAll(adj, color, x))
                    return false;   
            }
            else if(color[x] == color[par])
                    return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[])
	{
	    vector<int> color(V, -1);
	    for(int i = 0; i < V; i++)
	    {
	        if(color[i] == -1)
	        {
	            if(!colorAll(adj, color, i))
	                return false;   
	        }
	    }
	    return true;
	}

};
