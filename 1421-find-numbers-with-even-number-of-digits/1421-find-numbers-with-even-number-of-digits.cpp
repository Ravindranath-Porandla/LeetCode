class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;

        for (int n : nums)
            if (!(((int)log10(n) + 1) & 1))
                res++;

        return res;
    }
};