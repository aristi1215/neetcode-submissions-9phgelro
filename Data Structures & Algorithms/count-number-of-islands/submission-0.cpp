class Solution {
public:

    void numIslands (vector<vector<char>> & grid, int r, int c){

        int rows = grid.size();
        int cols = grid[0].size();

        if(min(r,c) < 0 || r == rows || c == cols || grid[r][c] != '1') {
            return;
        }

        grid[r][c] = '#';

        numIslands (grid,r+1, c);
        numIslands (grid,r-1, c);
        numIslands (grid,r, c+1); 
        numIslands (grid,r, c-1);

    }

    int numIslands(vector<vector<char>>& grid) {

        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    numIslands(grid,i,j);
                    count++;
                }
            }
        }

        return count;
    }
};