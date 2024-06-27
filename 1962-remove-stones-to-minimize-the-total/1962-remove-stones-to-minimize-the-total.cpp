class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;

        for (int i = 0; i < piles.size(); i++) {
            pq.push(piles[i]);
        }

        while (!pq.empty() && k--) {
            int top = pq.top();
            pq.pop();
            int rem = top - top / 2;
            pq.push(rem);
        }
        
        int ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};