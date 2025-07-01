class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int cnt = 0;

        for (int i = 1; i < n; i++)
            if (word[i] == word[i - 1])
                cnt++;

        return cnt + 1;
    }
};