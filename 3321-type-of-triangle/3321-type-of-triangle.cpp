class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        if (a + b <= c || a + c <= b || c + b <= a)
            return "none";
        if (a == b && b == c)
            return "equilateral";
        if (a == b || a == c || b == c)
            return "isosceles";
        else
            return "scalene";
    }
};