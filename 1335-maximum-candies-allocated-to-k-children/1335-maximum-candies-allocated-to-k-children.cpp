class Solution {
public:
    int isPossible(vector<int>& candies, long long k, int mid) {
        long long cnt = 0;

        for (int c : candies) {
            cnt += c / mid;
        }

        return cnt >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = accumulate(candies.begin(), candies.end(), 0LL);
        if (k > sum)
            return 0;

        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        int res = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(candies, k, mid)) {
                low = mid + 1;
                res = mid;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};