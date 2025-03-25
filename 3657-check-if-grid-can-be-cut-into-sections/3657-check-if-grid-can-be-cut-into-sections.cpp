class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return canPartition(rectangles, 0, 0, 2) || canPartition(rectangles, 1, 1, 3);
    }

private:
    bool canPartition(std::vector<std::vector<int>>& rectangles, int axis, int startIndex, int endIndex) {
        std::sort(rectangles.begin(), rectangles.end(), [&](const std::vector<int>& a, const std::vector<int>& b) {
            return a[axis] < b[axis];
        });
        int lineCount = 0;
        int sectionStart = rectangles[0][startIndex];
        int sectionEnd = rectangles[0][endIndex];

        for (const auto& rect : rectangles) {
            if (rect[startIndex] < sectionEnd) {
                sectionEnd = std::max(rect[endIndex], sectionEnd);
            } else {
                lineCount++;
                sectionStart = rect[startIndex];
                sectionEnd = rect[endIndex];
            }
        }

        return lineCount >= 2;
    }
};