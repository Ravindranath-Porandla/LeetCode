class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n = nums.size();
        long long x = 0;
        long long total = (n * (n + 1) / 2);
        long long left = 0;
        long long right = 0;
        long long cnt = 0;
        int maxi = INT_MIN;
        for(int n : nums){
            maxi = max(maxi, n);
        }

        while(left <= right && right < n){
            if(nums[right] == maxi){
                cnt++;
            }

            while(cnt >= k && left <= right){
                if(nums[left] == maxi){
                    cnt--;
                }
                left++;
            }

            x += right - left + 1;
            right++;
        }

        return total - x;
    }
};