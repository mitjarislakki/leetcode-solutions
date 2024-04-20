// Daily 20.4.2024
// 1992. Find All Groups of Farmland
// https://leetcode.com/problems/find-all-groups-of-farmland/submissions/1237180584/

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        int rows = land.size();
        int cols = land[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(land[i][j]){
                    int k = i+1;
                    int l = j+1;
                    // Find right
                    while(l < cols && land[i][l]) l++;
                    // Find bottom
                    while(k < rows && land[k][j]) k++;
                    // Clear farmland
                    for(int r = i; r < k; r++){
                        for(int c = j; c < l; c++)
                            land[r][c] = 0;
                    }
                    
                    vector<int> farm = {i, j, k-1, l-1};
                    res.push_back(farm);
                }
            }
        }
        return res;
    }
};