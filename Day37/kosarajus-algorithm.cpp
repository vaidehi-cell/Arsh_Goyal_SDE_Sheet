class Solution
{
	public:
	vector<int> vec;
	//Function to find number of strongly connected components in the graph.
    void dfs(int node, vector<int> adj[], int trans, map<int, bool> &vis)
    {
        vis[node] = true;
        for(auto x: adj[node])
            if(!vis[x])
                dfs(x, adj, trans, vis);
        if(trans == 0)
            vec.push_back(node);
    }
    int kosaraju(int V, vector<int> adj[])
    {
        int ans = 0;
        vector<int> transpose[V];
        map<int, bool> vis;
        for(int i = 0; i < V; i++)
        {
            for(auto x: adj[i])
                transpose[x].push_back(i);
        }
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
                dfs(i, adj, 0, vis);
        }
        for(int i = 0; i < V; i++)
            vis[i] = false;
            
        for(int i = V-1; i > -1; i--)
        {
            if(!vis[vec[i]])
            {
                dfs(vec[i], transpose, 1, vis);
                ans++;
            }
        }
        return ans;
    }
};
