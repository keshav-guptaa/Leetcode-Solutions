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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long ans = 0;
        while(!q.empty()){
            int sz = q.size();
            long long mn = q.front().second;
            int first, last;
            for(int i = 0; i < sz; i++){
                auto node = q.front().first;
                long long id = q.front().second - mn;
                q.pop();
                if(i == 0) first = id;
                if(i == sz - 1) last = id;
                
                if(node -> left){
                    q.push({node -> left, 2*id + 1});
                }
                if(node -> right){
                    q.push({node -> right, 2*id + 2});
                }
            }
            if(ans < last - first + 1) ans = last - first + 1;
        }
        return int(ans);
    }
};