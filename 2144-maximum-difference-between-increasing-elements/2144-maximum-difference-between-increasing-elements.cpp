class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;

        int res = -1;
        for (int num : nums) {
            if (!pq.empty() && num > pq.top())
                res = max(res, num - pq.top());
            pq.push(num);
        }

        return res;
    }
};