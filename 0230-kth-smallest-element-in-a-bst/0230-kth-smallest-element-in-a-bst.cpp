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
    void inorder(TreeNode* root, int k, int &count, int &ans, bool &f){
        if(root == NULL) return; 
        inorder(root -> left, k, count, ans, f);
        count++;
        if(count == k){
            ans = root -> val;
            f = 1;
        }
        inorder(root -> right, k, count, ans, f);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = -1;
        bool f = 0;
        inorder(root, k, count, ans, f);
        return ans;
    }
};