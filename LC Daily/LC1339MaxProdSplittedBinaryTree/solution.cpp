class Solution {
public:
    int calcTotalSum(TreeNode* node) {
        int left = node->left ? calcTotalSum(node->left) : 0;
        int right = node->right ? calcTotalSum(node->right) : 0;
        return node->val + left + right;
    }

    int calculateMaxProduct(TreeNode* node, long long& maxProduct, int totalSum) {
        int left = 0, right = 0;

        if (node->left) {
            left = calculateMaxProduct(node->left, maxProduct, totalSum);
            maxProduct = max(maxProduct, 1LL * left * (totalSum - left));
        }

        if (node->right) {
            right = calculateMaxProduct(node->right, maxProduct, totalSum);
            maxProduct = max(maxProduct, 1LL * right * (totalSum - right));
        }

        return node->val + left + right;
    }

    int maxProduct(TreeNode* root) {
        int totalSum = calcTotalSum(root);
        long long maxProduct = 0;
        calculateMaxProduct(root, maxProduct, totalSum);
        return maxProduct % 1000000007;
    }
};
