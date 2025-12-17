class Solution {
public:
    int n{0};
    //state 0-> no stock, 1-> hold stock after buy, 2-> hold stock after short sell
    long long recurse(int index, int k, int state, vector<int>& prices, vector<vector<vector<long long>>>& dp){
        if(index==n ||k==0) return state == 0 ? 0 : LLONG_MIN / 2;

        //consider
        long long ans=LLONG_MIN;
        if(dp[index][k][state]!=-1) return dp[index][k][state];
        if(state==0){
            ans = max(ans, -1*prices[index]+recurse(index+1, k, 1, prices, dp));
            ans = max(ans, prices[index]+recurse(index+1, k, 2, prices, dp));
            ans = max(ans, recurse(index+1, k, 0, prices, dp));
        }
        else if(state==1){
            ans = max(ans, prices[index]+recurse(index+1, k-1, 0, prices, dp));
            ans = max(ans, recurse(index+1, k, state, prices, dp));
            
        }
        else {
            ans = max(ans, -1*prices[index]+recurse(index+1, k-1, 0, prices, dp));
            ans = max(ans, recurse(index+1, k, state, prices, dp));
            
        }
        dp[index][k][state]=ans;
        return ans;
    }
    long long maximumProfit(std::vector<int>& prices, int k) {
        n = static_cast<int>(prices.size());
        std::vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(k+1, vector<long long>(3, -1)));
        return recurse(0, k, 0, prices, dp);
    }
};