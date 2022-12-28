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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int f = p -> val, s = q -> val;
        while(true){
            int r = root -> val;
            if((r > f && r < s)|| (r < f && r > s) || r == f || r == s){
                return root;
            }
            else if(r < f && r < s) root = root -> right;
            else root = root -> left;
        }
    }
};