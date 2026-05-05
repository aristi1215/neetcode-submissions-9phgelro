class Solution {
public:

    void BFSisland(vector<vector<int>> & grid) {
        
        queue<pair<int,int>> q;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        vector<pair<int,int>> directions = {{0,1},{0,-1},{-1,0},{1,0}};

        for(int i = 0; i < grid.size();i++){
            for(int j = 0; j < grid[i].size();j++) {
                if(grid[i][j] == 0) {
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }


        while(!q.empty()) {

            int qsize = q.size();
            int dist = 0;

            for(int i = 0; i < qsize; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                dist++;
                for(auto & [dr,dc] : directions) {
                    int rowDist = r+dr;
                    int colDist = c+dc;
                    if(rowDist < 0 || colDist < 0 || rowDist >= ROWS || colDist >= COLS || grid[rowDist][colDist] == -1 || visited[rowDist][colDist]){
                        continue;
                    }
                    if(grid[rowDist][colDist] == 2147483647){
                        grid[rowDist][colDist] = grid[r][c]+1;
                    }
                    visited[rowDist][colDist] = true;
                    q.push({rowDist,colDist});
                }
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
       BFSisland(grid);
    }
};
