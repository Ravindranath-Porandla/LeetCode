class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        unordered_set<int> st;
        long long int ans = 0;

        while (st.size() != n) {
            auto top = pq.top();
            pq.pop();
            int val = top.first;
            int idx = top.second;

            if (st.find(idx) == st.end()) {
                ans += val;
                st.insert(idx);

                if (idx - 1 >= 0 && st.find(idx - 1) == st.end()) {
                    st.insert(idx - 1);
                    pq.push({nums[idx - 1], idx - 1});
                }
                if (idx + 1 < n && st.find(idx + 1) == st.end()) {
                    st.insert(idx + 1);
                    pq.push({nums[idx + 1], idx + 1});
                }
            }
        }

        return ans;
    }
};
