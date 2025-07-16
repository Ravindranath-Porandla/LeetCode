class Solution {
public:
    int maximumLength(vector<int>& nums) {

        return max(healper_for_even_sum_seq(nums),
                   healper_for_odd_sum_seq(nums));
    }
    int healper_for_odd_sum_seq(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int cnt_1 = 0;

        while (i < n && nums[i] % 2 == 0)
            i++;

        int sign = 1;
        while (i < n) {
            if (nums[i] % 2 == sign) {
                cnt_1++;
                sign = 1 - sign;
            }
            i++;
        }

        i = 0;
        int cnt_2 = 0;

        while (i < n && nums[i] % 2 == 1)
            i++;

        sign = 0;
        while (i < n) {
            if (nums[i] % 2 == sign) {
                cnt_2++;
                sign = 1 - sign;
            }
            i++;
        }

        return max(cnt_1, cnt_2);
    }
    int healper_for_even_sum_seq(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for (int num : nums) {
            if (num % 2 == 0)
                cnt++;
        }

        return max(cnt, n - cnt);
    }
};