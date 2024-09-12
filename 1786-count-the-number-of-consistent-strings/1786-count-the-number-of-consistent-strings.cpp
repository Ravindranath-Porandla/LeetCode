class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<int> st;
        for (char ch : allowed)
            st.insert(ch);

        int ans = 0;
        for (string s : words) {
            bool flag = true;
            for (char ch : s) {
                if (st.find(ch) == st.end()) {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
                ans++;
        }
        return ans;
    }
};