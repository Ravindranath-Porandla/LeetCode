class Solution {
public:
    int find_digits_sum(int n){
        int sum = 0;
        while(n){
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>>> mp;

        for(int num : nums){
            mp[find_digits_sum(num)].push(num);
        }

        int res = -1;
        for(auto it : mp){
            auto pq = it.second;
            if(pq.size() >= 2){
                int x = pq.top();
                pq.pop();
                int y = pq.top();

                res = max(x + y, res);
            }
        }

        return res;
    }
};