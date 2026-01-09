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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return root;
        unordered_map<TreeNode*, TreeNode*> parentMap;
        parentMap[root] = nullptr;
        unordered_map<int, vector<TreeNode*>> levelMap;
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            level++;
            int t = q.size();
            for(int i=0;i<t;i++){
                levelMap[level].push_back(q.front());
                if(q.front()->left){
                    q.push(q.front()->left);
                    parentMap[q.front()->left] = q.front();
                }
                if(q.front()->right) {
                    q.push(q.front()->right);
                    parentMap[q.front()->right] = q.front();
                }
                q.pop();
            }
            //cout<<level<<endl;
        }
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> travelUp;
        
        for(TreeNode* i:levelMap[level]){
            travelUp.push(i);
            visited.insert(i);
        }
        while(travelUp.size()>1){
            int t = travelUp.size();
            for(int i=0;i<t;i++){
                if(visited.count(parentMap[travelUp.front()])==0){
                    travelUp.push(parentMap[travelUp.front()]);
                    visited.insert(parentMap[travelUp.front()]);
                }
                travelUp.pop();
            }
        }
        return travelUp.front();
    }
};
