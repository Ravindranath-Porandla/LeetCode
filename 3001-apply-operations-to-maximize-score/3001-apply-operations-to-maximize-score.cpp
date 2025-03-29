class Solution {
private:
    int primeFactorCount(int num) {
        int factorCount = 0;
        if (num % 2 == 0) {
            factorCount++;
            while (num % 2 == 0) {
                num /= 2;
            }
        }

        for (long long divisor = 3; divisor * divisor <= num; divisor += 2) {
            if (num % divisor == 0) {
                factorCount++;
                while (num % divisor == 0) {
                    num /= divisor;
                }
            }
        }
        if (num > 1)
            factorCount++;
        return factorCount;
    }

    int powerMod(int base, int exponent, int modValue) {
        long long result = 1;
        long long baseMod = base % modValue;
        while (exponent > 0) {
            if (exponent & 1) {
                result = (result * baseMod) % modValue;
            }
            baseMod = (baseMod * baseMod) % modValue;
            exponent >>= 1;
        }
        return (int)result;
    }

public:
    int maximumScore(vector<int>& elements, int stepsRemaining) {
        int size = (int)elements.size();
        if (size == 0)
            return 1;

        priority_queue<pair<int, int>> maxHeap;
        vector<int> nextGreater(size, size), prevGreater(size, -1),
            primeScore(size, 0);
        stack<int> forwardStack, backwardStack;

        for (int i = 0; i < size; i++) {
            primeScore[i] = primeFactorCount(elements[i]);
            maxHeap.emplace(elements[i], i);
        }

        for (int i = 0; i < size; i++) {
            while (!forwardStack.empty() &&
                   primeScore[i] > primeScore[forwardStack.top()]) {
                nextGreater[forwardStack.top()] = i;
                forwardStack.pop();
            }
            forwardStack.push(i);
        }

        for (int i = size - 1; i >= 0; i--) {
            while (!backwardStack.empty() &&
                   primeScore[i] >= primeScore[backwardStack.top()]) {
                prevGreater[backwardStack.top()] = i;
                backwardStack.pop();
            }
            backwardStack.push(i);
        }

        int finalScore = 1;
        const int MODULO = 1000000007;

        while (!maxHeap.empty() && stepsRemaining > 0) {
            auto [value, index] = maxHeap.top();
            maxHeap.pop();

            long long totalSteps = 1LL * (nextGreater[index] - index) *
                                   (index - prevGreater[index]);
            long long stepsToUse = min(totalSteps, (long long)stepsRemaining);

            int multiplier = powerMod(value, (int)stepsToUse, MODULO);
            finalScore = (int)((1LL * finalScore * multiplier) % MODULO);

            stepsRemaining -= stepsToUse;
        }
        return finalScore % MODULO;
    }
};