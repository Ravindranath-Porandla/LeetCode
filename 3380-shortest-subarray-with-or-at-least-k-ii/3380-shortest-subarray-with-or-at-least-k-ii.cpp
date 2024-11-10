class BitCounter {
public:
    int bitCounts[30] = {}, value = 0;
    void add(int x) {
        for (int i = 0; x; x >>= 1, ++i)
            if (x & 1)
                bitCounts[i]++, value |= (1 << i);
    }
    void remove(int x) {
        for (int i = 0; x; x >>= 1, ++i)
            if (x & 1)
                bitCounts[i]--, (bitCounts[i] == 0) && (value &= ~(1 << i));
    }
};

class Solution {
public:
    int minimumSubarrayLength(vector<int>& v, int k, int res = INT_MAX) {
        BitCounter counter;
        for (int i = 0, j = 0; i < v.size(); ++i) {
            counter.add(v[i]);
            while (counter.value >= k && j <= i)
                res = min(res, i - j + 1), counter.remove(v[j++]);
        }
        return res == INT_MAX ? -1 : res;
    }
};