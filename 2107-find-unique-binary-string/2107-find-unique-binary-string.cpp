class Solution {
public:
    string solve(int idx, int n, string str, unordered_set<string>& st) {
        if (idx == n) {
            if (st.find(str) == st.end()) {
                return str;
            }
            return "";
        }
        // pick 0
        string x = solve(idx + 1, n, str + '0', st);
        // pick 1
        string y = solve(idx + 1, n, str + '1', st);

        return max(x, y);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(), nums.end());
        string str;
        return solve(0, nums[0].size(), str, st);
    }
};