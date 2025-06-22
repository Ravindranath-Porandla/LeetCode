class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int n = s.size();

        for (int i = 0; i < n; i += k) {
            string sub_str = s.substr(i, min(k, n - i + 1));
            res.push_back(sub_str);
        }

        if (n % k)
            for (int i = 0; i < (k - (n % k)); i++)
                res.back().push_back(fill);

        return res;
    }
};