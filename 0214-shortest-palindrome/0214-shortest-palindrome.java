class Solution {
    public String shortestPalindrome(String s) {
        int n = s.length();
        StringBuilder str = new StringBuilder(s);
        String rev = str.reverse().toString();

        for(int i = 0; i < n; i++){
            if(s.substring(0,n - i).equals(rev.substring(i, n))){
                return rev.substring(0, i) + s;
            }
        }
        return "";
    }
}