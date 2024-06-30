class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();

        priority_queue<int, vector<int>, greater<int>> left;
        priority_queue<int, vector<int>, greater<int>> right;

        int i = 0;
        int j = n - 1;

        int workers = 0;
        long long int ans = 0;
        while (workers < k) {
            while (left.size() < candidates && i <= j) {
                left.push(costs[i]);
                i++;
            }
            while (right.size() < candidates && i <= j) {
                right.push(costs[j]);
                j--;
            }

            int left_top = (left.size() == 0) ? INT_MAX : left.top();
            int right_top = (right.size() == 0) ? INT_MAX : right.top();

            if (left_top <= right_top) {
                ans += left_top;
                left.pop();
            } else {
                ans += right_top;
                right.pop();
            }
            workers++;
        }

        return ans;
    }
};