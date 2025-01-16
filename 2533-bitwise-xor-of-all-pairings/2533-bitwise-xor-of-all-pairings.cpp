class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int ans = 0;
        if (n & 1) {
            for (int num : nums2) {
                ans ^= num;
            }
        }

        if (m & 1) {
            for (int num : nums1) {
                ans ^= num;
            }
        }

        return ans;
    }
};