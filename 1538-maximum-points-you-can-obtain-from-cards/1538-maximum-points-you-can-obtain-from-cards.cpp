class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;

        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }

        int x = k - 1;
        int ans = INT_MIN;
        ans = max(ans, sum);
        int y = n - 1;

        while (x >= 0) {
            sum -= cardPoints[x];
            sum += cardPoints[y];
            x--;
            y--;
            ans = max(ans, sum);
        }
        return ans;
    }
};