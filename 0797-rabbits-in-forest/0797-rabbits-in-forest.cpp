class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        unordered_map<int, int> mpp;
        for (auto it : answers) {
            mpp[it]++;
        }
        for (auto it : mpp) {
            int size = it.first + 1;
            int num = it.second / size;
            if (it.second % size)
                num++;
            ans += (num * size);
        }
        return ans;
    }
};