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
    void f(TreeNode* root, int val, int curr, int depth){
        if(!root) return;
        if(curr == depth-1){
            TreeNode* node1 = new TreeNode(val, root->left, NULL);
            root->left = node1;
            TreeNode* node2 = new TreeNode(val, NULL, root->right);
            root->right = node2;
            return;
        }
        
        f(root->left, val, curr+1, depth);
        f(root->right, val, curr+1, depth);
        return;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* new_node = new TreeNode(val);
            new_node -> left = root;
            return new_node;
        }
        f(root, val, 1, depth);
        return root;
    }
};