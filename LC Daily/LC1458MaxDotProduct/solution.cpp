class Solution {
public:

    int calculate(int index1, int index2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
        if(index1==nums1.size() || index2==nums2.size()){
            return INT_MIN;
        }
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        int ans = INT_MIN;
        int next = calculate(index1+1, index2+1, nums1, nums2, dp);
        next = max(0, next);  
        ans = max(ans, nums1[index1]*nums2[index2]+next);
        //ans = max(ans, next);
        ans = max(ans, calculate(index1+1, index2, nums1, nums2, dp));
        ans = max(ans, calculate(index1, index2+1, nums1, nums2, dp));
        dp[index1][index2]=ans;
        return ans;

    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1));
        return calculate(0, 0, nums1, nums2, dp);
    }
};