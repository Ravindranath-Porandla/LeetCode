class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XOR = 0;
        for (int d : derived) {
            XOR ^= d;
        }

        if (!XOR)
            return true;
        return false;
    }
};