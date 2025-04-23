class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num] += num; // store total points for each number
        }

        // Extract and sort unique numbers
        vector<int> uniqueNums;
        for (auto& p : freq) {
            uniqueNums.push_back(p.first);
        }
        sort(uniqueNums.begin(), uniqueNums.end());

        unordered_map<int, int> memo;
        return solve(0, uniqueNums, freq, memo);
    }

    int solve(int idx, vector<int>& uniqueNums, unordered_map<int, int>& freq,
              unordered_map<int, int>& memo) {
        if (idx >= uniqueNums.size())
            return 0;
        if (memo.count(idx))
            return memo[idx];

        // Option 1: Skip current
        int skip = solve(idx + 1, uniqueNums, freq, memo);

        // Option 2: Take current
        int take = freq[uniqueNums[idx]];
        if (idx + 1 < uniqueNums.size() &&
            uniqueNums[idx + 1] == uniqueNums[idx] + 1) {
            take += solve(idx + 2, uniqueNums, freq, memo); // skip adjacent
        } else {
            take += solve(idx + 1, uniqueNums, freq, memo);
        }

        return memo[idx] = max(skip, take);
    }
};
