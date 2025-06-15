class Solution {
public:
    int maxDiff(int num) {
        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;

        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                long long n = num;
                long long newNum = 0;
                long long pos = 1;

                while (n) {
                    int lastDigit = n % 10;
                    n /= 10;
                    if (lastDigit == i)
                        lastDigit = j;
                    newNum = lastDigit * pos + newNum;
                    pos *= 10;
                }

                if (newNum != 0 && 
                    (floor(log10(newNum)) + 1 == floor(log10(num)) + 1)) {
                    maxi = max(maxi, newNum);
                    mini = min(mini, newNum);
                }
            }
        }

        return abs(maxi - mini);
    }
};
