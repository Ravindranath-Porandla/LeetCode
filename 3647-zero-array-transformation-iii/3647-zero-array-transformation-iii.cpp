class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        int m = q.size();
        sort(q.begin(), q.end());
        int ans = 0;
        int j = 0;

        priority_queue<int> possible;
        priority_queue<int, vector<int>, greater<int>> choosen;

        for (int i = 0; i < n; i++) {

            while (!choosen.empty() && choosen.top() < i)
                choosen.pop();

            while (j < m && q[j][0] == i) {
                possible.push(q[j][1]);
                j++;
            }

            if(nums[i])
            nums[i] -= choosen.size();

            while (nums[i] > 0 && !possible.empty() && possible.top() >= i) {
                nums[i]--;
                choosen.push(possible.top());
                possible.pop();
                ans++;
            }

            if (nums[i] > 0)
                return -1;
            
        }

        return m - ans;
    }
};