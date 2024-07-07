class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int emptyBottles = numBottles;
        int filledBottles = 0;

        while (emptyBottles >= numExchange) {
            filledBottles = emptyBottles / numExchange;
            ans += filledBottles;
            emptyBottles -= (filledBottles * numExchange);
            emptyBottles += (filledBottles);
        }

        return ans;
    }
};