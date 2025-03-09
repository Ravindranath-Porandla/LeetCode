class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int length = 1;
        int last = colors[0];
        int res = 0;

        for (int i = 1; i < n; i++) {
            if (colors[i] == last) {
                length = 1;
                continue;
            }
            length++;
            if (length >= k) {
                res++;
            }
            last = colors[i];
        }

        for (int i = 0; i < k - 1; i++) {
            if (colors[i] == last) {
                length = i;
                break;
            }
            length++;
            if (length >= k) {
                res++;
            }
            last = colors[i];
        }

        return res;
    }
};