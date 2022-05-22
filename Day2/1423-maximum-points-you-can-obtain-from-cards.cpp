class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int pre[n+1];
        pre[0] = 0;
        for(int i = 1; i < n + 1; i++)
            pre[i] = pre[i-1] + cardPoints[i-1];
        int sum = pre[n], ans = 0;
        for(int i = n - k; i <= n; i++)
            ans = max(ans, sum -(pre[i] - pre[i - n + k]));
        return ans;
    }
};
