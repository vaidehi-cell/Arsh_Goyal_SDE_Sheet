class Solution {
public:
    void filler(vector<vector<int>>& image, int sr, int sc, int newColor, int value)
    {
        if(sr < 0 || sr > image.size()-1 || sc < 0 || sc > image[0].size()-1)
            return;
        if(image[sr][sc] != value)
            return;
        image[sr][sc] = newColor;
        filler(image, sr-1, sc, newColor, value);
        filler(image, sr+1, sc, newColor, value);
        filler(image, sr, sc+1, newColor, value);
        filler(image, sr, sc-1, newColor, value);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)     {
        if(image[sr][sc] != newColor)
            filler(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};
