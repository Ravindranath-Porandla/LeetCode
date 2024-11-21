class Solution {
public:
    bool isPossible(int mid, vector<int>& piles, int h) {
        long long int x = 0;
        for (int pile : piles) {
            x += ceil((double)pile / (double)mid);
        }
        return (x <= h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(mid, piles, h)) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};