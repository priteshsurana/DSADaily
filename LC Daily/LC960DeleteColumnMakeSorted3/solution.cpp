class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int backtrack(int index, vector<string>& strs, int indexTaken) {
        if (index == strs[0].size()) return 0;

        if (dp[index][indexTaken + 1] != -1)
            return dp[index][indexTaken + 1];

        int ans = INT_MAX;

        // delete this column
        ans = 1 + backtrack(index + 1, strs, indexTaken);

        // keep this column if valid
        if (indexTaken == -1) {
            ans = min(ans, backtrack(index + 1, strs, index));
        } else {
            bool isValid = true;
            for (int i = 0; i < n; i++) {
                if (strs[i][indexTaken] > strs[i][index]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                ans = min(ans, backtrack(index + 1, strs, index));
            }
        }

        return dp[index][indexTaken + 1] = ans;
    }

    int minDeletionSize(vector<string>& strs) {
        n = strs.size();
        int m = strs[0].size();
        dp.assign(m, vector<int>(m + 1, -1));
        return backtrack(0, strs, -1);
    }
};
