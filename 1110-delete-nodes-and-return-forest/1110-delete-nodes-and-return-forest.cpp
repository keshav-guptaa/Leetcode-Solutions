class Solution {
public:
    
    vector<TreeNode*> ans;
    unordered_set<int> s;
    
    void solve(TreeNode* &root){
        if(root != NULL){
            solve(root->left);
            solve(root->right);
            if(s.find(root->val) != s.end())
            {
                if(root->left)  ans.push_back(root->left);
                if(root->right) ans.push_back(root->right);
                root = NULL;
            }
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto &it: to_delete) s.insert(it);
        solve(root);
        if(root) ans.push_back(root);
        return ans;
    }
};