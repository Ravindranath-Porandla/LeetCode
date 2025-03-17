class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> freq(501, 0);

        for (int num : nums) {
            freq[num] ^= num;
        }

        for (int f : freq) {
            if (f)
                return false;
        }

        return true;
    }
};