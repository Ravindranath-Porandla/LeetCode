class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if (s1.size() < s2.size()) {
            swap(s1, s2);
        }

        vector<string> vec1, vec2;
        stringstream stream1(s1);
        string word;

        while (stream1 >> word) {
            vec1.push_back(word);
        }

        stringstream stream2(s2);

        while (stream2 >> word) {
            vec2.push_back(word);
        }

        int i = 0;
        int j = vec1.size() - 1;
        int k = 0;
        int l = vec2.size() - 1;

        while (i < vec1.size() && k < vec2.size() && vec1[i] == vec2[k]) {
            i++;
            k++;
        }

        while (l >= k && l >= k && j >= i && vec1[j] == vec2[l]) {
            l--;
            j--;
        }

        return l < k;
    }
};