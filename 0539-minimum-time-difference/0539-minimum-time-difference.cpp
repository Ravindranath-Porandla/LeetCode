class Solution {
public:
    int timeDiff(string s1, string s2) {
        int min1 = stoi(s1.substr(0, 2)) * 60 + stoi(s1.substr(3, 2));
        int min2 = stoi(s2.substr(0, 2)) * 60 + stoi(s2.substr(3, 2));
        return min(abs(min1 - min2), 1440 - abs(min1 - min2));
    }
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int n = timePoints.size();
        int ans = INT_MAX;

        for (int i = 0; i < n - 1; i++) {
            ans = min(ans, timeDiff(timePoints[i], timePoints[i + 1]));
        }
        ans = min(ans, timeDiff(timePoints[0], timePoints[n - 1]));
        return ans;
    }
};