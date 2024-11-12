class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;
        int maxi = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == maxi) {
                cnt++;
            } else {
                cnt--;
            }
            if (cnt == 0) {
                maxi = nums[i];
                cnt = 1;
            }
        }
        return maxi;
    }
};