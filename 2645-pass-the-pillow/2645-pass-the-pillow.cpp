class Solution {
public:
    int passThePillow(int n, int time) {
        int dir = time / (n - 1);

        if(time < n){
            return time + 1;
        }
        if(dir & 1){
            return (n - time % (n - 1));
        }else {
            return ((time % (n - 1)) + 1);
        }
        return 0;
    }
};