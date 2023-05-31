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
    vector<vector<int>> ans;
    vector<int> temp;
    
    bool isLeaf(TreeNode* root){
        return !root->left && !root->right;
    }
    
    void dfs(TreeNode* root, int target){
        if(!root) return;
        temp.push_back(root->val);
        if(isLeaf(root) && target == root->val){
            ans.push_back(temp);
            temp.pop_back();
            return;
        } 
        
        dfs(root->left, target-root->val);
        dfs(root->right, target-root->val);
        
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return ans;
    }
};