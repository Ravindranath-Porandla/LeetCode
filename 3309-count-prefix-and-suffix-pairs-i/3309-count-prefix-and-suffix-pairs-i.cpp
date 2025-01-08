class Solution {
public:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int n1 = str1.size();
        int n2 = str2.size();

        int i = 0;
        while (i < n1 && i < n2 && str1[i] == str2[i]) {
            i++;
        }
        if (i != n1) {
            return false; 
        }

        int j1 = n1 - 1, j2 = n2 - 1;
        while (j1 >= 0 && j2 >= 0 && str1[j1] == str2[j2]) {
            j1--;
            j2--;
        }
        if (j1 != -1) {
            return false; 
        }

        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};