class Solution {
public:
    int maximum69Number(int n) {
        string num = to_string(n);
        for (int i = 0; i < num.size(); i++) {
            if (num[i] == '6') {
                num[i] = '9';
                break;
            }
        }

        n = stoi(num);
        return n;
    }
};
