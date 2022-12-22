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
    bool isSymmetrichelp(TreeNode* l, TreeNode* r){
        if(l == NULL || r == NULL) return l == r;
        
        if(l -> val != r -> val) return false;
        
        return isSymmetrichelp(l -> left, r -> right) && isSymmetrichelp(l -> right, r -> left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return root == NULL || isSymmetrichelp(root -> left, root -> right);
    }
};