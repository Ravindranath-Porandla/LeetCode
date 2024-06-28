class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        // Step 1: Create a vector of vectors to store tasks with their original
        // indices
        vector<vector<int>> sortedTasks(n);

        for (int i = 0; i < n; i++) {
            sortedTasks[i] = {tasks[i][0], tasks[i][1], i};
        }

        // Step 2: Sort tasks based on starting time (tasks[i][0])
        sort(sortedTasks.begin(), sortedTasks.end());

        // Step 3: Use a priority queue to simulate processing tasks in order
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        long long int curTime = 0;
        int idx = 0;
        vector<int> res;

        // Step 4: Process tasks
        while (idx < n || !pq.empty()) {
            // Push tasks into priority queue as they become available
            while (idx < n && curTime >= sortedTasks[idx][0]) {
                pq.push({sortedTasks[idx][1], sortedTasks[idx][2]});
                idx++;
            }

            // If priority queue is not empty, process the task with smallest
            // processing time
            if (!pq.empty()) {
                pair<int, int> p = pq.top();
                pq.pop();
                curTime += p.first;
                res.push_back(p.second);
            } else {
                // If no tasks are available to process, move time forward to
                // next available task
                curTime = sortedTasks[idx][0];
            }
        }

        return res;
    }
};