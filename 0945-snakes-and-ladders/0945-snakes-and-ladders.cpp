class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<pair<int,int>> q;
        int n = board.size();
        vector<int> visited(n*n+1,0);
        q.push({1,0});
        visited[1]=1;
        int row,col,cell;        
        while(!q.empty()){
            auto [current,move] = q.front();
            q.pop();
            for(int dice=1;dice<=6;++dice){
                cell = current+dice;
                if(cell%n==0){
                    row = n-(cell/n);
                    col = (cell/n)&1?n-1:0;
                }else{
                    row = n-(cell/n)-1;
                    col = (cell/n)&1?n-(cell%n):(cell%n)-1;
                }
                if(board[row][col]!=-1){
                    cell = board[row][col];
                }
                if(cell == n*n) return move+1;
                if(!visited[cell]){
                    q.push({cell,move+1});
                    visited[cell]=1;
                }
            }
        }
        return -1;
    }
};