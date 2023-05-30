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
    int amountOfTime(TreeNode* root, int start) {
        
        queue<TreeNode*> q;
        map<TreeNode*, TreeNode*> m;
        unordered_map<TreeNode*, bool> vis;
        q.push(root);
        TreeNode* target;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto node = q.front();
                if(node->val == start) target = node;
                q.pop();
                if(node->left){
                    q.push(node->left);
                    m[node->left] = node;
                }
                if(node->right){
                    q.push(node->right);
                    m[node->right] = node;
                }
            }
        }
        q.push(target);
        vis[target] = 1;
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = 1;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = 1;
                }
                if(m[node] && !vis[m[node]]){
                    q.push(m[node]);
                    vis[m[node]] = 1;
                }
            }
            level++;
        }
        return level-1;
    }
};