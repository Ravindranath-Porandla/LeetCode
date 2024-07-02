class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        int i = 0;
        int j = 0;
        vector<int> ans;

        while (i < n1 && j < n2) {
            if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                i++;
            }
        }

        return ans;
    }
};