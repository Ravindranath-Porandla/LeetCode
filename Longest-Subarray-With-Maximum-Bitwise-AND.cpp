class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int cnt = 0;
        int ans = INT_MIN;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == maxi){
                cnt++;
                ans = max(cnt, ans);
            } else {
                cnt = 0;
            }
        }

        return ans;
    }
};