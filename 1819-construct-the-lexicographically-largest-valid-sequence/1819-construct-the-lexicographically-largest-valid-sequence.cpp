class Solution {
public:
    bool solve(int indx, vector<int>& res, vector<bool>& vis, int count, int n) {
        if (count == 2 * n - 1) {
            return true;
        }
        if (res[indx]) {
            return solve(indx + 1, res, vis, count, n);
        }
        for (int i = n; i >= 1; --i) {
            if (!vis[i]) {
                if (i == 1) {
                    vis[i] = true;
                    res[indx] = i;
                    if (solve(indx + 1, res, vis, count + 1, n)) {
                        return true;
                    }
                    vis[i] = false;
                    res[indx] = 0;
                } else if (indx + i < res.size() && !res[indx + i]) {
                    vis[i] = true;
                    res[indx] = i;
                    res[indx + i] = i;
                    if (solve(indx + 1, res, vis, count + 2, n)) {
                        return true;
                    }
                    vis[i] = false;
                    res[indx] = 0;
                    res[indx + i] = 0;
                }
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> res(2 * n - 1, 0);
        vector<bool> vis(n + 1, false);
        solve(0, res, vis, 0, n);
        return res;
    }
};