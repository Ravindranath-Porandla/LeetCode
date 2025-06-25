class Solution {
public:
    long long upper(vector<int>& nums, long long k) {
        int i = 0, j = nums.size();
        while (i < j) {
            int mid = (i + j) / 2;
            if (nums[mid] <= k) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }
        return i;
    }

    long long lower(vector<int>& nums, long long k) {
        long long ans = nums.size();
        int i = 0, j = nums.size();
        while (i < j) {
            int mid = (i + j) / 2;
            if (nums[mid] < k) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }
        return i;
    }

    long long f(vector<int>& nums1, vector<int>& nums2, long long mid) {
        long long c = 0;
        int n = nums1.size(), m = nums2.size();

        for (int i = 0; i < n; i++) {
            int x = nums1[i];
            if (x > 0) {
                long long target = floor((double)mid / x);
                c += upper(nums2, target);
            } else if (x < 0) {
                long long target = ceil((double)mid / x);
                c += m - lower(nums2, target);
            } else {
                if (mid >= 0)
                    c += m;
            }
        }
        return c;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {

        long long i = -1e10, j = 1e10, ans = 0;

        while (i <= j) {
            long long mid = (i + j) / 2;
            long long c = f(nums1, nums2, mid);
            if (c >= k) {
                ans = mid;
                j = mid - 1;
            } else
                i = mid + 1;
        }
        return ans;
    }
};