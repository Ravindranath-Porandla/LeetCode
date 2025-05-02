class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int last_right = -1, last_left = 0;

        for (int i = 0; i < n; ++i) {
            char c = dominoes[i];

            if (c == 'R') {
                if (last_right != -1) {
                    for (size_t r = last_right + 1; r < i; ++r) {
                        dominoes[r] = 'R';
                    }
                }
                last_right = i;
            } else if (c == 'L') {
                if (last_right != -1) {
                    for (size_t left_p = last_right + 1, right_p = i - 1;
                         left_p < right_p; left_p++, right_p--) {
                        dominoes[left_p] = 'R';
                        dominoes[right_p] = 'L';
                    }
                    last_right = -1;
                } else {
                    for (size_t l = last_left; l < i; ++l) {
                        dominoes[l] = 'L';
                    }
                }
                last_left = i;
            }
        }

        if (last_right != -1) {
            for (int i = last_right + 1; i < n; ++i) {
                dominoes[i] = 'R';
            }
        }

        return dominoes;
    }
};