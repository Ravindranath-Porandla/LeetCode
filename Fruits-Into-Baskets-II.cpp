class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = baskets.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (baskets[j] != -1 && baskets[j] >= fruits[i]) {
                    fruits[i] = -1;
                    baskets[j] = -1;
                    break;
                }
            }
        }

        int cnt = 0;
        for (int f : fruits) {
            if (f != -1) {
                cnt++;
            }
        }

        return cnt;
    }
};