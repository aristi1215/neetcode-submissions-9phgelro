
class Solution {
public:

    void floodFill (vector<vector<int>>& image, int sr, int sc, vector<vector<bool>> & visited, int startingColor, int newColor ) {

        int rows = image.size();
        int cols = image[0].size(); 


        if(sr == rows || sc == cols || min(sr, sc) < 0 
        || visited[sr][sc] || image[sr][sc] != startingColor) {
            return;
        }

        visited[sr][sc] = true;
        image[sr][sc] = newColor;


        floodFill(image, sr+1,sc,visited,startingColor,newColor);
        floodFill(image, sr-1,sc,visited,startingColor,newColor);
        floodFill(image, sr,sc+1,visited,startingColor,newColor);
        floodFill(image, sr,sc-1,visited,startingColor,newColor);

        visited[sr][sc] = false;
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {

        vector<vector<bool>> visited(image.size(),vector<bool>(image[0].size(),false));


        floodFill(image, sr,sc,visited,image[sr][sc],color);

        return image;
    }
};