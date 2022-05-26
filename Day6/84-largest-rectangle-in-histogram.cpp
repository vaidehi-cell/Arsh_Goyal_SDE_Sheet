class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int max_area = 0;
        stack<pair<int, int>> st;
        
        vector<int> nsr;
        for(int i = n - 1; i > -1; i--)
        {
            while(!st.empty() && st.top().first >= heights[i])
                st.pop();
            if(st.size() == 0)
                nsr.push_back(n);
            else
                nsr.push_back(st.top().second);
            st.push({heights[i], i});
        }
        reverse(nsr.begin(), nsr.end());
        
        while(!st.empty()) st.pop();
        
        vector<int> nsl;
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && st.top().first >= heights[i])
                st.pop();
            if(st.size() == 0)
                nsl.push_back(-1);
            else
                nsl.push_back(st.top().second);
            st.push({heights[i], i});
        }
        
        for(int i = 0; i < n; i++)
            max_area = max(max_area, (nsr[i] - nsl[i] - 1) * heights[i]);
        
        return max_area;
    }
};
