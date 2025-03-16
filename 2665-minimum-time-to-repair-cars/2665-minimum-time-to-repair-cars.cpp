class Solution {
public:
    bool isPossible(long long mid, vector<int>& ranks, int cars){
        long long cnt = 0;

        for(int i = 0; i < ranks.size(); i++){
            cnt += sqrt(mid / ranks[i]);
        }

        return cnt >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        int max_elem = *max_element(ranks.begin(), ranks.end());
        //int min_elem = *min_element(ranks.begin(), ranks.end());
        //sort(ranks.begin(), ranks.end());

        long long low = 1;
        long long high = (long)max_elem * cars * cars;
        long long ans = LONG_MAX;

        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(isPossible(mid, ranks, cars)){
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};