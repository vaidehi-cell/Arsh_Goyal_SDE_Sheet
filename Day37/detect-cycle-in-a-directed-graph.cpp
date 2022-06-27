class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool check(int node, vector<int> adj[], unordered_map<int,bool> &vis, unordered_map<int, bool> &vis1)
    {
        vis[node] = vis1[node] = true;
        for(auto x: adj[node])
        {
            if(!vis[x] && check(x, adj, vis, vis1))
                return true;
            else if(vis1[x])
                return true;
        }
        vis1[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) 
    {
        unordered_map<int, bool> vis, vis1;
        for(int i = 0; i < V; i++)
        {
            if(!vis[i] && check(i, adj, vis, vis1))
                return true;
        }
        return false;
    }
};
