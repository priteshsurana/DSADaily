class Solution {
public:
    int lcs(int index1, int index2, string& s1, string& s2, vector<vector<int>>& dp){
        if(index1==s1.size() || index2==s2.size()) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        int ans =0;
        if(s1[index1]==s2[index2]) ans = max(ans, s1[index1]+lcs(index1+1, index2+1, s1, s2, dp));
        ans = max(ans, lcs(index1, index2+1, s1, s2, dp));
        ans = max(ans, lcs(index1+1, index2, s1, s2, dp));
        dp[index1][index2] = ans;
        return ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        int sum1=0, sum2=0;
        for(char c:s1){
            sum1+=c;
        }
        for(char c:s2){
            sum2+=c;
        }
        int ans=0;
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        int commonSum = lcs(0, 0, s1, s2, dp);
        return sum1+sum2-commonSum-commonSum;
    }
};