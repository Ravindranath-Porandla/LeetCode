class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum = 0;
        int n = chalk.size();
        for (int i = 0; i < n; i++) {
            sum += chalk[i];
        }

        int rem = k % sum;

        for (int i = 0; i < n; i++) {
            if (rem < chalk[i]) {
                return i;
            }
            rem -= chalk[i];
        }
        return -1;
    }
};