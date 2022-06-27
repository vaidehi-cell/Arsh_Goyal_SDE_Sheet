class Solution {
public:
     bool isCycle(int node, vector<vector<int>> &graph, vector<bool> &vis,  vector<bool> &vis1)
     {
        vis[node] = vis1[node] = true;
        for(auto it : graph[node])
        {
            if(!vis[it])
            {
                if(isCycle(it, graph, vis, vis1)) 
                    return true;
            }
            else if(vis1[it]) 
                return true;
        }
        vis1[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        vector<int> ans;
        int n = graph.size();
        vector<bool> vis(n, false), vis1(n, false);
        for(int i = 0; i < n; i++)
        {
            if(!isCycle(i, graph, vis, vis1))
                ans.push_back(i);
        }
        return ans;
    }
};
