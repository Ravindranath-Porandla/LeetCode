class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = INT_MIN;
        int n = cardPoints.size();

        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        ans = max(ans, sum);

        int x = k - 1;
        int y = n - 1;

        while (x >= 0) {
            sum -= cardPoints[x];
            x--;
            sum += cardPoints[y];
            y--;
            ans = max(ans, sum);
        }

        return ans;
    }
};