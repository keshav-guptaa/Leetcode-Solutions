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
    int d1 = -1, d2 = -1;
    TreeNode* X;
    TreeNode* Y;
    
    void dfs(TreeNode* root, TreeNode* parent, int x, int y, int d){
        if(!root || (d1 != -1 && d2 != -1)) return;
        if(root->val == x){
            d1 = d;
            X = parent;
        } 
        else if(root->val == y){
            d2 = d;
            Y = parent;
        }
        else{
            dfs(root->left, root, x, y, d+1);
            dfs(root->right, root, x, y, d+1);
        }
        
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, NULL, x, y, 0);
        return X != Y && d1 == d2;
    }
};