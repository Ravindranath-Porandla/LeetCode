class Solution {
public:
    bool possible(int product, vector<int>& quantities, int shops){
        for(int q : quantities){
            shops -= ceil((q * 1.0)/product);

            if(shops < 0)
                return false;
        }

        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1;
        int r = *max_element(quantities.begin(), quantities.end());
        int res = 0;

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(possible(mid, quantities, n)){
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};