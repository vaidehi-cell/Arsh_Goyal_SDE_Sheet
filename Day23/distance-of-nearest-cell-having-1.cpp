class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int r = grid.size(), c = grid[0].size(), inf = 100000;
	    for(int i = 0; i < r; i++)
	    {
	        for(int j = 0; j < c; j++)
	        {
	            if(grid[i][j] != 1)
	            {
	               int top, left;
	                if(i > 0)
	                    top = grid[i-1][j];
    	            else
    	                inf;
	                if(j > 0)
	                    left = grid[i][j-1];
	                else
	                    left = inf;
	                grid[i][j] = min(top, left) + 1;
	            }
	        }
	    }
	    for(int i = r - 1; i > -1; i--)
	    {
	        for(int j = c - 1; j > -1; j--)
	        {
	            if(grid[i][j] != 1)
	            {
	                int bottom, right;
	                if(i + 1 < r)
	                    bottom = grid[i + 1][j];
	                else
	                    bottom = inf;
	                if(j + 1 < c)
	                    right = grid[i][j + 1];
	                else
	                    right = inf;
	                grid[i][j] = min(grid[i][j], 1 + min(bottom, right));
	            }
	        }
	    }
	    for(int i = 0; i < r; i++)
	        for(int j = 0; j < c; j++)
	            grid[i][j]--;
	    return grid;
	}
};
