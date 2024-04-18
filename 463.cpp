// Daily 18.4.2024
// 463. Island Perimeter
// https://leetcode.com/problems/island-perimeter/submissions/1235557233/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int score = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    // left
                    if(j < 1 || !grid[i][j-1]) score++;
                    // right
                    if(j >= m-1 || !grid[i][j+1]) score++;
                    // up
                    if(i < 1 || !grid[i-1][j]) score++;
                    // down
                    if(i >= n-1 || !grid[i+1][j]) score++;
                }
            }
        }
        return score;
    }
};