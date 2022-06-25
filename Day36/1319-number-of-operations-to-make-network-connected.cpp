class Solution {
public:  
    void visit(vector<int> adj[], int i, vector<bool> &visited)
    {
        visited[i] = true;
        for(auto it: adj[i])
        {
            if(!visited[it]) 
                visit(adj, it, visited);
        }
    }
    int makeConnected(int n, vector<vector<int>> &connections) 
    {
        if(connections.size() < n - 1) 
            return -1;
        vector<bool>visited(n,0);
        vector<int>adj[n];
        for(int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int components = 0;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                components++;
                visit(adj, i, visited);
            }
        }
        return components - 1;  
    }
};
