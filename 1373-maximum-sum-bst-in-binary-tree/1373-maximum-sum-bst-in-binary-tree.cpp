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
    vector<int> helper(TreeNode* root, int& mx){
        if(!root) return {INT_MAX, INT_MIN, 0};
        auto left = helper(root->left, mx);
        auto right = helper(root->right, mx);
        if(left[1] < root->val && root->val < right[0]){
            mx = max(mx, left[2] + right[2] + root->val);
            return {min(left[0], root->val), max(root->val, 
            right[1]), left[2] + right[2] + root->val};
        }
        return {INT_MIN, INT_MAX, max(left[2], right[2])};
    }
    
    int maxSumBST(TreeNode* root) {
        int mx = 0;
        helper(root, mx);
        return mx;
    }
};