class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int ans = 0;
        while (1) {
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();

            if (top1 == 0 || top2 == 0)
                break;
            ans++;
            pq.push(top1 - 1);
            pq.push(top2 - 1);
        }

        return ans;
    }
};