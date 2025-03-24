class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<vector<int>> intervals;

        for(auto &meeting : meetings){
            if((intervals.size() == 0) || (intervals.back()[1] < meeting[0])){
                intervals.push_back(meeting);
            } else {
                intervals.back()[1] = max(intervals.back()[1], meeting[1]);
            }
        }

        int ans = 0;

        for(auto &interval : intervals){
            ans += (interval[1] - interval[0] + 1);
        }

        return days - ans;
    }
};