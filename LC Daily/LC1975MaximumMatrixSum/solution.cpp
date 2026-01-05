class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int n = matrix[0].size();
        int mini = INT_MAX;
        int negativeCounter=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans+=abs(matrix[i][j]);
                negativeCounter+=(matrix[i][j]<0?1:0);
                mini = min(mini, abs(matrix[i][j]));
            }
        }
        if(negativeCounter%2!=0){
            ans-=(2*mini);
        }
        return ans;
    }
};