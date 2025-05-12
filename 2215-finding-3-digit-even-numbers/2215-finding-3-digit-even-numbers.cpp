class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& nums) {
        int n = nums.size();
        set<int> st;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(i == j)  continue;
                for (int k = 0; k < n; k++) {
                    if(j == k || i == k)    continue;  
                    if (!(nums[k] % 2) && nums[i]) {
                        st.insert(nums[i] * 100 + nums[j] * 10 + nums[k]);
                    }
                }
            }
        }

        vector<int> res;
        for (int num : st) {
            res.push_back(num);
        }

        return res;
    }
};