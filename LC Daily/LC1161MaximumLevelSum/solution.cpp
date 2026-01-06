/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ansIndex = 0;
        long long maxSum = LONG_MIN;
        int currIndex = 0;
        while(!q.empty()){
            currIndex++;
            int t = q.size();
            long long currSum = 0;
            for(int i=0;i<t;i++){
                currSum += q.front()->val;
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();

            }
            if(currSum>maxSum){
                maxSum = currSum;
                ansIndex = currIndex; 
            }
        }
        return ansIndex;
    }
};