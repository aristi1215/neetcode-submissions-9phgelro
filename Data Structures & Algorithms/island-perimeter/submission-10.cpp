class Solution {
public:

    int DFSisland(vector<vector<int>>& grid, int row, int col) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        if(row < 0 || col < 0 || row >= rowSize || col >= colSize || grid[row][col] == 0){
            return 1;
        }
        if(grid[row][col] == 2) {
            return 0;
        }

        int count = 0;
        grid[row][col] = 2;

        count += DFSisland(grid,row,col+1);
        count += DFSisland(grid,row,col-1);
        count += DFSisland(grid,row+1,col);
        count += DFSisland(grid,row-1,col);

        return count;

    }

    int islandPerimeter(vector<vector<int>>& grid) {

        int initialRow = 0;
        int initialCol = 0;

       for(int row = 0; row < grid.size(); row++){
        for(int col = 0; col < grid[row].size(); col++) {
            if(grid[row][col] == 1){
                initialRow = row;
                initialCol = col;
                break;
            }
        }
        if(grid[row][initialCol] == 1){
            break;
        }
       }

        return DFSisland(grid,initialRow,initialCol);

    }
};