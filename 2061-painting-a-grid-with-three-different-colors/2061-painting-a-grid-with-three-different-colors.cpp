class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;

    // Encode a column's coloring as an int
    int encode(const vector<int>& col) {
        int code = 0;
        for (int i = 0; i < m; i++) {
            code = code * 4 + col[i]; // base 4 encoding (1-3 values only)
        }
        return code;
    }

    // Generate all valid column colorings (no adjacent same color in column)
    void generateColumns(int idx, vector<int>& temp, vector<vector<int>>& all) {
        if (idx == m) {
            all.push_back(temp);
            return;
        }

        for (int color = 1; color <= 3; ++color) {
            if (idx == 0 || temp[idx - 1] != color) {
                temp[idx] = color;
                generateColumns(idx + 1, temp, all);
            }
        }
    }

    // Check if two column colorings are valid together (no same color in same
    // row)
    bool isCompatible(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < m; ++i) {
            if (a[i] == b[i])
                return false;
        }
        return true;
    }

    // Main recursive function with memoization
    int dfs(int colIdx, int prevColCode, unordered_map<long long, int>& memo,
            unordered_map<int, vector<int>>& codeToCol,
            unordered_map<int, vector<int>>& transitions) {

        if (colIdx == n)
            return 1;

        long long key = ((long long)colIdx << 20) | prevColCode;
        if (memo.count(key))
            return memo[key];

        int ans = 0;
        for (int nextCode : transitions[prevColCode]) {
            ans = (ans +
                   dfs(colIdx + 1, nextCode, memo, codeToCol, transitions)) %
                  MOD;
        }

        return memo[key] = ans;
    }

    int colorTheGrid(int _m, int _n) {
        m = _m;
        n = _n;

        // Step 1: Generate all valid columns
        vector<vector<int>> allCols;
        vector<int> temp(m);
        generateColumns(0, temp, allCols);

        unordered_map<int, vector<int>> codeToCol;   // code -> column coloring
        unordered_map<int, vector<int>> transitions; // valid transitions

        for (auto& col : allCols) {
            int code = encode(col);
            codeToCol[code] = col;
        }

        // Step 2: Build transition map
        for (auto& [code1, col1] : codeToCol) {
            for (auto& [code2, col2] : codeToCol) {
                if (isCompatible(col1, col2)) {
                    transitions[code1].push_back(code2);
                }
            }
        }

        // Step 3: Start DFS from all valid first columns
        unordered_map<long long, int> memo;
        int result = 0;
        for (auto& [startCode, _] : codeToCol) {
            result =
                (result + dfs(1, startCode, memo, codeToCol, transitions)) %
                MOD;
        }

        return result;
    }
};
