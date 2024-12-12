class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long int ans = 0;
        priority_queue<int, vector<int>> pq;

        for (int gift : gifts) {
            pq.push(gift);
        }

        while (k--) {
            int x = sqrt(pq.top());
            pq.pop();
            pq.push(x);
        }

        while(k-- && !pq.empty()){
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};