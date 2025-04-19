class Solution {
public:
    int LB(vector<int>& vec, int target, int start) {
        int low = start;
        int high = vec.size() - 1;
        int res = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vec[mid] == target) {
                res = mid;
                high = mid - 1;
            } else if (vec[mid] > target) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }

    int UB(vector<int>& vec, int target, int start) {
        int low = start;
        int high = vec.size() - 1;
        int res = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vec[mid] == target) {
                res = mid;
                low = mid + 1;
            } else if (vec[mid] > target) {
                high = mid - 1;
            } else {
                res = mid;
                low = mid + 1;
            }
        }

        return res;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        //vector<int> vec;
        sort(nums.begin(), nums.end());
        long long int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            // nums[j] >= lower -  nums[i]
            int p1 = LB(nums, lower - nums[i], i + 1);
            // nums[j] <= upper - nums[i]
            int p2 = UB(nums, upper - nums[i], i + 1);
            if (p1 != -1 && p2 != -1 && p2 >= p1) {
                ans += (p2 - p1 + 1);
            }
        }

        return ans;
    }
};