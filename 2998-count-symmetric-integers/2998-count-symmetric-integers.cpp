class Solution {
public:
    int isSymmetric(int n) {
        int no_of_digits = (log10(n) + 1);
        if (no_of_digits & 1)
            return false;

        int half = no_of_digits / 2;
        int half_sum_1 = 0;

        while (half--) {
            half_sum_1 += n % 10;
            n /= 10;
        }

        half = no_of_digits / 2;
        int half_sum_2 = 0;

        while (half--) {
            half_sum_2 += n % 10;
            n /= 10;
        }

        return (half_sum_1 == half_sum_2);
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;

        for (int n = low; n <= high; n++) {
            if (isSymmetric(n)) {
                cnt++;
            }
        }

        return cnt;
    }
};