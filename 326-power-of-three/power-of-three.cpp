class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        int x = log10(n) / log10(3);
        if (pow(3, x) == n)
            return true;
        return false;
    }
};