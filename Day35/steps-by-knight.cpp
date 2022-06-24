class Solution 
{
    #include <bits/stdc++.h>
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	pair<int, int> dirs[8] = {{-1,2},{-1,-2},{2,1},{2,-1},{1,2},{1,-2},{-2,1},{-2,-1}};
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int ans = 0;
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
        q.push({KnightPos[0], KnightPos[1]});
        visited[KnightPos[1] - 1][KnightPos[0] - 1] = true;
        q.push({-1, -1});
        while(!q.empty())
        {
            if(q.front().second == -1 && q.front().first == -1)
            {
                q.push({-1, -1});
                q.pop();
                ans++;
            }
            int x = q.front().first, y = q.front().second;
            q.pop();
            if(x == TargetPos[0] && y == TargetPos[1])
               return ans;
            for(int i = 0; i < 8; i++)
            {
                int x1 = x + dirs[i].first, y1 = y + dirs[i].second;
                if(x1 < 1 || x1 > N || y1 < 1 || y1 > N || visited[x1][y1] == true)
                    continue;
                else
                {
                    q.push({x1, y1});
                    visited[x1][y1] = true;
                }
            }
        }
        return -1;
	}
};
