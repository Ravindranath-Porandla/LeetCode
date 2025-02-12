class Solution {
    void solve(List<List<Integer>> res, List<Integer> ds, int[] nums, boolean vis[]){
        if(ds.size() == nums.length){
            res.add(new ArrayList<>(ds));
            return;
        }

        for(int i = 0; i < nums.length; i++){
            if(vis[i] == false){
                vis[i] = true;
                ds.add(nums[i]);
                solve(res, ds, nums, vis);
                ds.remove(ds.size() - 1);
                vis[i] = false;
            }
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> ds = new ArrayList<>();

        int n = nums.length;
        boolean[] vis = new boolean[n];
        Arrays.fill(vis, false);
        
        solve(res, ds, nums, vis);

        return res;
    }
}