class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int maxi = 0;
        int sum = 0;

        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        int start = 0;
        for (int i = k - 1; i >= 0; i--) {
            maxi = max(sum, maxi);
            sum -= cardPoints[i];
            sum += cardPoints[cardPoints.size() - k + i];
        }
        maxi = max(sum, maxi);
        return maxi;
    }
};