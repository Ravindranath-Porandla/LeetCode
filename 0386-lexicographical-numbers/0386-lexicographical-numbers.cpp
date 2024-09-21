class Solution {
public:
    static bool cmp(int a, int b){
        string s1 = to_string(a);
        string s2 = to_string(b);

        if(s1 < s2)   return true;
        else        return false;
    }
    vector<int> lexicalOrder(int n) {
        vector<int> arr;
        for(int i = 1; i <= n; i++){
            arr.push_back(i);
        }
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};