class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;
        for (int& num : nums)
            st.insert(num);

        sort(nums.begin(), nums.end());

        if (nums[0] < k)
            return -1;
        if (nums[0] != k)
            return st.size();
        if (nums[0] == k)
            return st.size() - 1;

        return -1;
    }
};