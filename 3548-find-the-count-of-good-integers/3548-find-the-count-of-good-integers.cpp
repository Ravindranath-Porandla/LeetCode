class Solution {
public:
    long long countGoodIntegers(int length, int divisor) {
        static long long combinations[11][11];
        for (int i = 0; i <= 10; i++) {
            combinations[i][0] = combinations[i][i] = 1;
        }
        for (int index = 2; index <= 10; index++) {
            for (int counter = 1; counter < index; counter++) {
                combinations[index][counter] =
                    combinations[index - 1][counter] +
                    combinations[index - 1][counter - 1];
            }
        }
        int prefixLimit = 1;
        for (int i = 0; i < (length + 1) / 2; i++)
            prefixLimit *= 10;

        std::vector<long long> frequencyCodes;
        for (int firstHalf = prefixLimit / 10; firstHalf < prefixLimit;
             firstHalf++) {
            long long currentNumber = firstHalf;
            for (int j = 0,
                     reflection = ((length & 1) ? firstHalf / 10 : firstHalf);
                 j < length / 2; j++)
                currentNumber = currentNumber * 10 + (reflection % 10),
                reflection /= 10;
            if (currentNumber % divisor == 0) {
                int counts[10] = {};
                for (int digitIndex = 0; digitIndex < length; digitIndex++)
                    counts[currentNumber % 10]++, currentNumber /= 10;
                currentNumber = 0;
                for (int digitValue = 0; digitValue < 10; digitValue++)
                    currentNumber = currentNumber * 11 + counts[digitValue];
                frequencyCodes.push_back(currentNumber);
            }
        }

        std::sort(frequencyCodes.begin(), frequencyCodes.end());
        frequencyCodes.erase(
            std::unique(frequencyCodes.begin(), frequencyCodes.end()),
            frequencyCodes.end());

        long long goodCount = 0;
        for (long long patternCode : frequencyCodes) {
            int counts[10] = {};
            for (int digitValue = 9; digitValue >= 0; digitValue--)
                counts[digitValue] = patternCode % 11, patternCode /= 11;
            long long arrangements = 1;
            for (int i = 0, remaining = length; i < 10; i++)
                arrangements *=
                    combinations[i ? remaining : remaining - 1][counts[i]],
                    remaining -= counts[i];
            goodCount += arrangements;
        }
        return goodCount;
    }
};