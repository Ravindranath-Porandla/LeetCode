class Solution {
public:
    void add(vector<int>& freq, int num) {
        for (int i = 0; i < 31; i++) {
            if (num & (1 << i)) {
                freq[i]++;
            }
        }
    }

    void remove(vector<int>& freq, int num) {
        for (int i = 0; i < 31; i++) {
            if (num & (1 << i)) {
                freq[i]--;
            }
        }
    }

    bool isValid(vector<int>& freq) {
        for (int f : freq) {
            if (f > 1) {
                return false;
            }
        }
        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int ans = 1;
        vector<int> freq(31, 0);

        while (right < n && left <= right) {
            add(freq, nums[right]);
            while (left <= right && !isValid(freq)) {
                remove(freq, nums[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};