class Solution {
public:
    long long kMirror(int base, int count) {
        string digits = "0"; 
        long long sum = 0;

        for (int found = 0; found < count;) {
            digits = nextSymmetric(digits, base);
            long long val = stoll(toDecimal(digits, base));
            string s = to_string(val);
            if (s == string(s.rbegin(), s.rend())) {
                sum += val;
                found++;
            }
        }
        return sum;
    }

private:
    string toDecimal(const string& digits, int base) {
        long long val = 0;
        for (char c : digits)
            val = val * base + (c - '0');
        return to_string(val);
    }

    string nextSymmetric(string digits, int base) {
        int half = digits.size() / 2;
        for (int i = half; i < digits.size(); i++) {
            if (digits[i] - '0' + 1 < base) {
                char nextDigit = '0' + (digits[i] - '0' + 1);
                digits[i] = digits[digits.size() - 1 - i] = nextDigit;
                for (int j = half; j < i; j++)
                    digits[j] = digits[digits.size() - 1 - j] = '0';
                return digits;
            }
        }
        return "1" + string(digits.size() - 1, '0') + "1";
    }
};