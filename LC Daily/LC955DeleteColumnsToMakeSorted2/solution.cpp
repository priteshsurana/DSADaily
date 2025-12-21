class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        unordered_set<int> deletedCols;
        vector<int> keptCols;

        for (int col = 0; col < m; col++) {
            bool isSorted = true;
            bool hasEqual = false;

            for (int row = 1; row < n; row++) {

                // Case 1: no columns kept yet
                if (keptCols.empty()) {
                    if (strs[row][col] < strs[row - 1][col]) {
                        deletedCols.insert(col);
                        isSorted = false;
                        break;
                    }
                    if (strs[row][col] == strs[row - 1][col]) {
                        hasEqual = true;
                    }
                }
                // Case 2: columns already kept
                else {
                    int k = 0;
                    while (k < keptCols.size() &&
                           strs[row][keptCols[k]] == strs[row - 1][keptCols[k]]) {
                        k++;
                    }

                    if (k < keptCols.size()) {
                        if (strs[row][keptCols[k]] > strs[row - 1][keptCols[k]]) {
                            continue;
                        } else {
                            deletedCols.insert(keptCols[k]);
                            isSorted = false;
                            break;
                        }
                    }

                    if (strs[row][col] < strs[row - 1][col]) {
                        deletedCols.insert(col);
                        isSorted = false;
                        break;
                    }
                    if (strs[row][col] == strs[row - 1][col]) {
                        hasEqual = true;
                    }
                }
            }

            if (isSorted && !hasEqual) {
                return deletedCols.size();
            }

            if (isSorted) {
                keptCols.push_back(col);
            }
        }

        return deletedCols.size();
    }
};
