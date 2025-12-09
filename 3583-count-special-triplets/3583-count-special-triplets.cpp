class Solution {
public:
    // nums[i] == nums[j] * 2 == nums[k]
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> right;
        int n = nums.size();

        for (int i = 2; i < n; i++) {
            right[nums[i]]++;
        }

        unordered_map<int, int> left;
        left[nums[0]]++;
        long long cnt = 0;
        int mod = 1e9 + 7;

        for (int i = 1; i < n - 1; i++) {
            long long l = 0;
            int d = 2 * nums[i];
            if (left.find(d) != left.end()) {
                l = left[d];
            }
            long long r = 0;
            if (right.find(d) != right.end()) {
                r = right[d];
            }
            cnt = (cnt + (l * r) % mod) % mod;
            right[nums[i + 1]]--;
            left[nums[i]]++;
        }

        return int(cnt % mod);
    }
};