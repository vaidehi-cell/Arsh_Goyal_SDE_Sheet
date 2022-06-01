class Solution {
public:
    int dist(vector<int> p, vector<int> q)
    {
        return (p[0]-q[0])*(p[0]-q[0]) + (p[1]-q[1])*(p[1]-q[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int d1 = dist(p1, p2), d2 = dist(p2, p3);
        int d3 = dist(p3, p4), d4 = dist(p1, p4);
        int d5 = dist(p2, p4), d6 = dist(p1, p3);
        
        vector<int> distances = {d1, d2, d3, d4, d5, d6};
        sort(distances.begin(), distances.end());
        
        if(distances[0] == distances[1] && distances[1] == distances[2] && distances[2] == distances[3])
        {
            if(distances[0] > 0)
            {
                if(distances[4] == distances[5])
                {
                    if(distances[4] == 2 * distances[0])
                        return true;
                }
            }
        }
        return false;
    }
};
