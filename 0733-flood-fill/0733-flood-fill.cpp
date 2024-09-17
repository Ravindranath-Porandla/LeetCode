class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image, int color, int drow[], int dcol[], int n, int m, int initColor){
        image[row][col] = color;

        for(int i= 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[nrow][ncol] != color && image[nrow][ncol] == initColor){
                dfs(nrow, ncol, image, color, drow, dcol, n, m, initColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int drow[] = {1, -1, 0, 0};
        int dcol[] = {0, 0, 1, -1};

        int initColor = image[sr][sc];

        dfs(sr, sc, image, color, drow, dcol, n, m, initColor);
        return image;
    }
};