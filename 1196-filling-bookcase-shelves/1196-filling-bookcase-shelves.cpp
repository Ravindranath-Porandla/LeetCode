class Solution {
public:
    int minHeightShelves(std::vector<std::vector<int>>& books, int shelfWidth) {
        return arrangeBooks(books, shelfWidth);
    }

private:
    int arrangeBooks(std::vector<std::vector<int>>& books, int maxShelfWidth) {
        std::vector<int> minHeights(books.size() + 1, INT_MAX);
        minHeights[0] = 0;

        for (int bookIndex = 1; bookIndex <= books.size(); bookIndex++) {
            int currentShelfHeight = 0;
            int currentShelfWidth = 0;

            for (int lastBook = bookIndex - 1; lastBook >= 0; lastBook--) {
                int currentBookThickness = books[lastBook][0];
                int currentBookHeight = books[lastBook][1];

                if (currentShelfWidth + currentBookThickness > maxShelfWidth) {
                    break;
                }

                currentShelfWidth += currentBookThickness;
                currentShelfHeight =
                    std::max(currentShelfHeight, currentBookHeight);

                int currentArrangementHeight =
                    minHeights[lastBook] + currentShelfHeight;
                minHeights[bookIndex] =
                    std::min(minHeights[bookIndex], currentArrangementHeight);
            }
        }

        return minHeights[books.size()];
    }
};