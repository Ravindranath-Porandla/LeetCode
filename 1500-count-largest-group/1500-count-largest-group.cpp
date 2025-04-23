class Solution {
public:
    int sumOfAllDigits(int num) {
        int sum = 0;

        while (num) {
            sum += (num % 10);
            num /= 10;
        }

        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int maxi = 0;

        for (int i = 1; i <= n; i++) {
            int s = sumOfAllDigits(i);
            mp[s]++;
            maxi = max(maxi, mp[s]);
        }

        int res = 0;

        for (auto& it : mp) {
            if (it.second == maxi) {
                res++;
            }
        }

        return res;
    }
};