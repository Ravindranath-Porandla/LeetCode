class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int freq[201] = {};
        for (int num : nums)
            freq[num + 100]++;
        sort(nums.begin(), nums.end(), [&freq](int a, int b) {
            return freq[a + 100] == freq[b + 100]
                       ? a > b
                       : freq[a + 100] < freq[b + 100];
        });
        return nums;
    }
};