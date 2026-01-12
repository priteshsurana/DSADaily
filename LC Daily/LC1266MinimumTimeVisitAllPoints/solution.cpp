class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time=0;        
        for(int i=1;i<points.size();i++){
            int x = points[i-1][0];
            int y = points[i-1][1];
            int nextx = points[i][0];
            int nexty = points[i][1];
            time+=(max(abs(nextx-x), abs(nexty-y)));
        }
        return time;
    }
};