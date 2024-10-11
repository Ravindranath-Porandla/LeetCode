class Solution {
public:
    typedef pair<int, int> P;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        int targetFrndArrival = times[targetFriend][0];

        sort(times.begin(), times.end());

        priority_queue<P, vector<P>, greater<P>> occupied;
        priority_queue<int, vector<int>, greater<int>> free;
        int chairs = 0;
        for (auto it : times) {
            int arrival = it[0];
            int depart = it[1];

            while (!occupied.empty() && occupied.top().first <= arrival) {
                free.push(occupied.top().second);
                occupied.pop();
            }

            if (free.empty()) {
                occupied.push({depart, chairs});
                if (arrival == targetFrndArrival)
                    return chairs;
                chairs++;
            } else {
                int leastFreeChair = free.top();
                free.pop();
                if (arrival == targetFrndArrival)
                    return leastFreeChair;
                occupied.push({depart, leastFreeChair});
            }
        }
        return -1;
    }
};