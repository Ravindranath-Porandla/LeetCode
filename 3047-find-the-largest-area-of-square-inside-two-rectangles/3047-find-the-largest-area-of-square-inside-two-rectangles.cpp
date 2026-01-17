class Solution {
public:
    long long intersection_area(const vector<int>& rect1_bl,
                                const vector<int>& rect1_tr,
                                const vector<int>& rect2_bl,
                                const vector<int>& rect2_tr) {
        int x_overlap = max(0, min(rect1_tr[0], rect2_tr[0]) -
                                   max(rect1_bl[0], rect2_bl[0]));
        int y_overlap = max(0, min(rect1_tr[1], rect2_tr[1]) -
                                   max(rect1_bl[1], rect2_bl[1]));
        long long int ans = min(x_overlap, y_overlap);
        return ans * ans;
    }

    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        long long max_area = 0;
        int n = bottomLeft.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long intersect_area = intersection_area(
                    bottomLeft[i], topRight[i], bottomLeft[j], topRight[j]);
                max_area = max(max_area, intersect_area);
            }
        }
        return max_area;
    }
};
