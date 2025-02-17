class Solution {
public:
    int numTilePossibilities(string tileSet) {
        unordered_set<string> uniqueSequences;
        vector<bool> isUsed(tileSet.length(), false);

        // Generate all possible sequences, including the empty string
        generateSequences(tileSet, "", isUsed, uniqueSequences);

        // Subtract 1 to exclude the empty string from the count
        return uniqueSequences.size() - 1;
    }

private:
    void generateSequences(string& tileSet, string currentSequence,
                           vector<bool>& isUsed,
                           unordered_set<string>& uniqueSequences) {
        // Add current sequence to the set
        uniqueSequences.insert(currentSequence);

        // Try adding each unused character to the current sequence
        for (int index = 0; index < tileSet.length(); ++index) {
            if (!isUsed[index]) {
                isUsed[index] = true;
                generateSequences(tileSet, currentSequence + tileSet[index],
                                  isUsed, uniqueSequences);
                isUsed[index] = false;
            }
        }
    }
};
