class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                freq[product]++;
            }
        }

        int sum = 0;
        for (auto [key, count] : freq) {
            if (count > 1) {
                sum += (count * (count - 1)) / 2;
            }
        }

        return sum * 8;
    }
};