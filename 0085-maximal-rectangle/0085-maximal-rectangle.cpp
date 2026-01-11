class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> st;

        for (int i = 0; i <= heights.size(); ++i) {
            while (!st.empty() &&
                   (i == heights.size() || heights[st.top()] > heights[i])) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, h * w);
            }
            st.push(i);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;

        int ans = 0;
        vector<int> hist(matrix[0].size(), 0);

        for (auto& row : matrix) {
            for (int i = 0; i < row.size(); ++i)
                hist[i] = row[i] == '0' ? 0 : hist[i] + 1;
            ans = max(ans, largestRectangleArea(hist));
        }

        return ans;
    }
};