class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for(int num : nums){
            pq.push(num);
        }

        int cnt = 0;

        while(pq.top() < k){
            long long x = (long long)pq.top();
            pq.pop();
            long long y = (long long)pq.top();
            pq.pop();

            pq.push(x * 2 + y);
            cnt++;
        }

        return cnt;
    }
};