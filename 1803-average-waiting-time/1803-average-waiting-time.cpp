class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int curTime = 0;
        long long totalWaitTime = 0;

        for (auto customer : customers) {
            int arrival = customer[0];
            int time = customer[1];

            if (curTime < arrival) {
                curTime = arrival;
            }
            int waitTime = curTime + time - arrival;
            totalWaitTime += waitTime;
            curTime += time;
        }

        return (double)(totalWaitTime) / customers.size();
    }
};