class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int res = INT_MIN;
        int sum = 0;

        for (int num : nums) {
            sum += num;

            if (sum < 0) {
                sum = 0;
            } else {
                res = max(res, sum);
            }
        }

        sum = 0;

        for (int num : nums) {
            num = num * -1;
            sum += num;

            if (sum < 0) {
                sum = 0;
            } else {
                res = max(res, sum);
            }
        }

        return res;
    }
};