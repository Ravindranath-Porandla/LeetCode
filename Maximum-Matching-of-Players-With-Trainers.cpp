class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int cnt = 0;
        int i = players.size() - 1;
        int j = trainers.size() - 1;

        while (i >= 0 && j >= 0) {
            if (players[i] <= trainers[j]) {
                cnt++;
                i--;
                j--;
            } else {
                i--;
            }
        }

        return cnt;
    }
};