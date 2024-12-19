class Solution {
public:
    bool is_sorted(vector<int>& arr) {
        return std::is_sorted(arr.begin(), arr.end());
    }

    void solve(int idx, vector<int>& arr, int cnt, int& ans) {
        if (idx == arr.size()) {
            if (is_sorted(arr)) {
                ans = max(ans, cnt);
            }
            return;
        }

        for (int i = idx; i < arr.size(); i++) {
            vector<int> temp(arr.begin(), arr.end());
            sort(arr.begin() + idx, arr.begin() + i + 1); 
            solve(i + 1, arr, cnt + 1, ans);             
            arr = temp;
        }
    }

    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        solve(0, arr, 0, ans);
        return ans;
    }
};
