class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        // Create a vector of pairs where each pair is (nums2[i], nums1[i])
        vector<pair<int, int>> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = {nums2[i], nums1[i]};
        }

        // Sort nums in descending order based on nums2[i]
        sort(nums.begin(), nums.end(), greater<pair<int, int>>());

        // Use a priority queue to track the largest k-1 elements from nums1
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            // Add nums[i].second (nums1[i]) to the sum and to the priority
            // queue
            sum += nums[i].second;
            pq.push(nums[i].second);

            // If the size of the priority queue exceeds k-1, remove the
            // smallest element
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            // Calculate the score using the current sum and nums[i].first
            // (nums2[i])
            if (pq.size() == k) {
                ans = max(ans, sum * (long long)nums[i].first);
            }
        }

        return ans;
    }
};
