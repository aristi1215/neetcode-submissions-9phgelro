class Solution {
public:
    
    
    int orangesRotting(vector<vector<int>>& grid, int initialRow, int initialCol) {
        

        int rows = grid.size();
        int cols = grid[0].size();
        int minutes = 0;
        int fresh = 0;

        queue<pair<int,int>> q;
        vector<pair<int,int>> movements = {{0,1},{0,-1},{1,0},{-1,0}};


        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size();j++) {
                if(grid[i][j] == 1) {
                    fresh++;
                }
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }
        
    

        while(!q.empty()){ 
            int qsize = q.size();
            int currFresh = fresh;
            for(int i = 0; i < qsize;i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(auto & [dr,dc] : movements) {
                    if(min(r+dr,c+dc) < 0 || r+dr >= rows || c+dc >= cols || grid[r+dr][c+dc] != 1){
                        continue;
                    }

                    q.push({r+dr,c+dc});
                    grid[r+dr][c+dc] = 2;
                    fresh--;
                }
            }
            if(currFresh != fresh){
                minutes++;
            }
        }

        if(fresh == 0) {
            return minutes;
        }else {
            return -1;
        }

    }

    int orangesRotting(vector<vector<int>>& grid){

        return orangesRotting(grid,0,0);

    } 
};
