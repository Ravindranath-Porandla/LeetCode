class Solution {
public:
    int minimumBoxes(vector<int>& apples, vector<int>& capacity) {
        int sum = 0;
        for (int i = 0; i < apples.size(); i++) {
            sum += apples[i];
        }
        sort(capacity.begin(), capacity.end());
        int cnt = 0;
        for (int i = capacity.size() - 1; i >= 0; i--) {
            if (sum <= 0)
                break;
            else {
                sum = sum - capacity[i];
                cnt++;
            }
        }
        return cnt;
    }
};