class Solution {
public:
    int minMaxDifference(int num) {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                int n = num;
                int newNum = 0;
                int pos = 1;

                while (n) {
                    int lastDigit = n % 10;
                    n /= 10;
                    if (lastDigit == i)
                        lastDigit = j;
                    newNum = lastDigit * pos + newNum;
                    pos *= 10;
                }

                maxi = max(maxi, newNum);
                mini = min(mini, newNum);
            }
        }

        return abs(maxi - mini);
    }
};