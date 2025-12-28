class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int negativeCount=0;
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]<0){
                    negativeCount+=(n-j);
                    break;
                }
            }
        }
        return negativeCount;
    }
};
