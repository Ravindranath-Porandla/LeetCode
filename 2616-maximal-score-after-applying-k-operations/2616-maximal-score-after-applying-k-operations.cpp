class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<int> pq;

        for (int num : nums) {
            pq.push(num);
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            int top = pq.top();
            pq.pop();
            pq.push(ceil(top / 3.0));
            ans += top;
        }
        return ans;
    }
};