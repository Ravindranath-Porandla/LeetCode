class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();

        priority_queue<int> pq;
        for (int stone : stones) {
            pq.push(stone);
        }

        while (pq.size() != 1) {
            int h1 = pq.top();
            pq.pop();
            int h2 = pq.top();
            pq.pop();

            if (h1 > h2) {
                pq.push(h1 - h2);
            }
            if(pq.size() == 0)  return 0;

        }

        return pq.top();
    }
};