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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map< int, multiset<int> >> m;
        queue< pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            auto node = x.first;
            int vertical = x.second.first;
            int level = x.second.second;
            m[vertical][level].insert(node -> val);
            if(node -> left){
                q.push({node -> left, {vertical-1, level+1}});
            }
            if(node -> right){
                q.push({node -> right, {vertical+1, level+1}});
            }
        }
        for(auto x: m){
            vector<int> col;
            for(auto y: x.second){
                col.insert(col.end(), y.second.begin(), y.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};