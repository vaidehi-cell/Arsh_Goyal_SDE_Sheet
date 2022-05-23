class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        int x, y, z, w, dir = 0;
        x = 0, y = m-1, z = n-1, w = 0;
        while(x <= z && w <= y)
        {
            if(dir == 0)
            {
                for(int i = w; i <= y; i++)
                    ans.push_back(matrix[x][i]);
                x++;
            }    
            else if(dir == 1)
            {
                for(int i = x; i <= z; i++)
                    ans.push_back(matrix[i][y]);
                y--;
            }
            else if(dir == 2)
            {
                for(int i = y; i >= w; i--)
                    ans.push_back(matrix[z][i]);
                z--;
            }
            else
            {
                for(int i = z; i >= x; i--)
                    ans.push_back(matrix[i][w]);
                w++;                
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};
