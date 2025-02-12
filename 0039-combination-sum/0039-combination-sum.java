class Solution {
    static void solve(int idx, int target, List<List<Integer>> res, List<Integer> ds, int[] cand) {
        if (idx == cand.length) {
            if (target == 0) {
                res.add(new ArrayList<>(ds));
            }
            return;
        }

        // pick
        if (target >= cand[idx]) {
            ds.add(cand[idx]);
            solve(idx, target - cand[idx], res, ds, cand);
            ds.remove(ds.size() - 1);
        }

        // not-pic
        solve(idx + 1, target, res, ds, cand);
    }

    public List<List<Integer>> combinationSum(int[] cand, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> ds = new ArrayList<>();

        solve(0, target, res, ds, cand);
        return res;
    }
}