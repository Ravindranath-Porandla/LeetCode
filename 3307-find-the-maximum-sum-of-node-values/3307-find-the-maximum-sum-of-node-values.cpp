class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        long long int sum = 0;
        int cnt = 0;
        int mini = INT_MAX;

        for (int num : nums) {
            int x = (num ^ k);
            if (x > num) {
                sum += x;
                cnt++;
            } else {
                sum += num;
            }
            mini = min(mini, abs(num - x));
        }
        return (cnt % 2 == 1) ? (sum - mini) : sum;
    }
};