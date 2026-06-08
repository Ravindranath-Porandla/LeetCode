class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> nums1;
        int cnt = 0;
        vector<int> nums2;

        for (int num : nums) {
            if (num < pivot) {
                nums1.push_back(num);
            } else if (num == pivot) {
                cnt++;
            } else {
                nums2.push_back(num);
            }
        }

        while (cnt--) {
            nums1.push_back(pivot);
        }

        for (int num : nums2) {
            nums1.push_back(num);
        }

        return nums1;
    }
};