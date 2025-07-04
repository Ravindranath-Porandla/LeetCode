class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        k -= 1;
        int res = 0;

        for (int i = 0; i < operations.size() && i < 60; ++i) {
            if ((k >> i) & 1) {
                res += operations[i];
            }
        }

        return 'a' + res % 26;
    }
};