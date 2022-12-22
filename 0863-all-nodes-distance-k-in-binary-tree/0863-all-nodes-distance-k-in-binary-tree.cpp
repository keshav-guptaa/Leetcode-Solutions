/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        q.push(root);
        map<TreeNode*, TreeNode*> m;
        vector<int> ans;
        unordered_map<TreeNode*, bool> vis;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node -> left){
                q.push(node -> left);
                m[node -> left] = node;
            }
            if(node -> right){
                q.push(node -> right);
                m[node -> right] = node;
            }
        }
        q.push(target);
        vis[target] = 1;
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            if(level++ == k) break;
            for(int i = 0; i < sz; i++){
                auto node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node -> left);
                    vis[node -> left] = 1;
                }
                if(node->right && !vis[node->right]){
                    q.push(node -> right);
                    vis[node -> right] = 1;
                }
                if(m[node] && !vis[m[node]]){
                    q.push(m[node]);
                    vis[m[node]] = 1;
                }
            }
        }
        while(!q.empty()){
            auto node = q.front();
            //vis[node -> val] = 1;
            q.pop();
            ans.push_back(node -> val);
        }
        return ans;
    }
};