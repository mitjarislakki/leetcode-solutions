// Daily 19.4.2024
// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/submissions/1236524791

class Solution {
private:
    void removeIsland(vector<vector<char>>& grid, int i, int j){
        bool outOfBounds = i<0 || i==grid.size() || j<0 || j==grid[0].size() || grid[i][j] == '0';
        if(!outOfBounds){
            grid[i][j] = '0';
            // Left
            removeIsland(grid, i-1, j);
            removeIsland(grid, i+1, j);
            removeIsland(grid, i, j-1);
            removeIsland(grid, i, j+1);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int score = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == '1'){
                    score++;
                    removeIsland(grid, row, col);
                }
            }
        }
        return score;
    }
};