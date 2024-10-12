class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> group;
        sort(intervals.begin(), intervals.end());

        for (auto interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            if (group.size() == 0) {
                group.push(end);
            } else {
                int top = group.top();
                if (top < start) {
                    group.pop();
                }
                group.push(end);
            }
        }
        return group.size();
    }
};