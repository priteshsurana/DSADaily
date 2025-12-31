class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int counter=0;
        int m = grid.size(), n = grid[0].size();
        for(int i=0;i<m-2;i++){
            for(int j=0;j<n-2;j++){
                int temp = grid[i][j]+grid[i][j+1]+grid[i][j+2];
                if(grid[i][j]>9 ||
                   grid[i][j+1]>9 ||
                   grid[i][j+2]>9 ||
                   grid[i+1][j]>9 ||
                   grid[i+2][j]>9 ||
                   grid[i+1][j+1]>9 ||
                   grid[i+1][j+2]>9 ||
                   grid[i+2][j+1]>9 ||
                   grid[i+2][j+2]>9){
                    continue;
                   }
                
                unordered_set<int> uniqueNo{grid[i][j],
                   grid[i][j+1],
                   grid[i][j+2],
                   grid[i+1][j],
                   grid[i+1][j+1],
                   grid[i+1][j+2],
                   grid[i+2][j],
                   grid[i+2][j+1],
                   grid[i+2][j+2]>9};
                if(uniqueNo.size()!=9) {continue;}
                
                if(grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2]!=temp) continue;
                if(grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]!=temp) continue;
                if(grid[i][j]+grid[i+1][j]+grid[i+2][j]!=temp) continue;
                if(grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1]!=temp) continue;
                if(grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2]!=temp) continue;
                if(grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2]!=temp) continue;
                if(grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j]!=temp) continue;
                counter++;
            }
        }
        return counter;
    }
};