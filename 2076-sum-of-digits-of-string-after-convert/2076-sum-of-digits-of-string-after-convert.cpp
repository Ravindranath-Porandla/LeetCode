class Solution {
public:
    int getLucky(string s, int k) {
        string temp = "";
        for (char ch : s) {
            string num = to_string(ch - 'a' + 1);
            temp.append(num);
        }

        int sum = 0;
        for (char ch : temp) {
            sum += ch - '0';
        }

        while (--k > 0) {
            int newSum = 0;
            while (sum > 0) {
                newSum += sum % 10;
                sum /= 10;
            }
            sum = newSum;
        }

        return sum;
    }
};