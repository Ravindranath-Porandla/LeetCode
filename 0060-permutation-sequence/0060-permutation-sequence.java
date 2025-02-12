class Solution {
    void solve(List<String> res, StringBuilder ds, boolean vis[], int n){
        if(ds.length() == n){
            res.add(ds.toString());
            return;
        }

        for(int i = 0; i < n; i++){
            if(vis[i] == false){
                vis[i] = true;
                ds.append(i + 1);
                solve(res, ds, vis, n);
                vis[i] = false;
                ds.deleteCharAt(ds.length() - 1);
            }
        }
    }
    public String getPermutation(int n, int k) {
        List<String> res = new ArrayList<>();
        StringBuilder ds = new StringBuilder();

        boolean[] vis = new boolean[n];

        solve(res, ds, vis, n);
        return res.get(k - 1).toString();
    }
}