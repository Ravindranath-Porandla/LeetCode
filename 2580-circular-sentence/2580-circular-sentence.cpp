class Solution {
public:
    bool isCircularSentence(string sen) {
        int n = sen.size();

        for (int i = 0; i < n; i++) {
            if (sen[i] == ' ' && sen[i - 1] != sen[i + 1])
                return false;
        }
        if (sen[0] != sen[n - 1])
            return false;

        return true;
    }
};