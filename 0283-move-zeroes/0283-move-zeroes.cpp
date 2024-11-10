class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;
        for(int num : nums){
            if(!num){
                cnt++;
            }
        }
        int i = 0;
        int j = 0;
        while(i < n){
            if(nums[i]){
                nums[j] = nums[i];
                j++;
            }
            i++;
        }

        while(j < n){
            nums[j] = 0;
            j++;
        }
    }
};