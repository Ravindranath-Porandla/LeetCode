class Solution {
public:
    int maximumSwap(int num) {
        string n = to_string(num);
        string ans = n;
        for (int i = 0; i < n.size(); i++) {
            for (int j = i + 1; j < n.size(); j++) {
                swap(n[i], n[j]);
                ans = max(ans, n);
                swap(n[i], n[j]);
            }
        }
        return stoi(ans);
    }
};