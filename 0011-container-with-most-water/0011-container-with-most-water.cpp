class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int x = (min(height[left], height[right]) * (right - left));
            maxi = max(maxi, x);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxi;
    }
};