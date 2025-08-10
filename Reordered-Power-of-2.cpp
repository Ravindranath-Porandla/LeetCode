class Solution {
public:
    bool solve(vector<int>& digits, int cnt, long long num) {
        if (cnt == 0) {
            return num > 0 && (num & (num - 1)) == 0; // check power of two
        }

        for (int i = 0; i < digits.size(); i++) {
            if (digits[i] != -1) {
                int d = digits[i];
                if (num == 0 && d == 0)
                    continue; // skip leading zero

                digits[i] = -1;
                if (solve(digits, cnt - 1, num * 10 + d))
                    return true;
                digits[i] = d;
            }
        }
        return false;
    }

    bool reorderedPowerOf2(int n) {
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        return solve(digits, digits.size(), 0LL);
    }
};
