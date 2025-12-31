class Solution {
public:
    int row, col;
    bool bfs(vector<vector<int>> matrix){
        queue<pair<int, int>> q;
        for(int c = 0;c<col;c++){
            if(matrix[0][c]==0) {
                q.push({0, c});
                matrix[0][c] = 1;
            }
        }
        while(!q.empty()){
            int t = q.size();
            for(int i=0;i<t;i++){
                auto p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
                if(r==row-1) return true;
                if(r+1<row && matrix[r+1][c]==0){
                    matrix[r+1][c]=1;
                    q.push({r+1, c});
                }
                if(c+1<col && matrix[r][c+1]==0){
                    matrix[r][c+1]=1;
                    q.push({r, c+1});
                }
                if(r-1>=0 && matrix[r-1][c]==0){
                    matrix[r-1][c]=1;
                    q.push({r-1, c});
                }
                if(c-1>=0 && matrix[r][c-1]==0){
                    matrix[r][c-1]=1;
                    q.push({r, c-1});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        this->row = row;
        this->col = col;
        vector<vector<int>> matrix(row, vector<int>(col, 0));
        int ans = 0;

        //Binary Search
        int low = 1, high = row*col;
        while(low<high){
            int mid = low+(high-low)/2;
            for(int v=0;v<mid;v++){
                matrix[cells[v][0]-1][cells[v][1]-1] = 1;
            }
            if(bfs(matrix)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid;
            }
            for(int v=0;v<mid;v++){
                matrix[cells[v][0]-1][cells[v][1]-1] = 0;
            }
        }
        return ans;
    }
};