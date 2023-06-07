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
    
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ct = 0;
        vector<int> t1, t2;
        unordered_map<int, int> m;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto node = q.front();
                t1.push_back(node->val);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            t2 = t1;
            sort(t2.begin(), t2.end());
            for(int i = 0; i < t1.size(); i++) m[t1[i]] = i;
            for(int i = 0; i < t1.size(); i++){
                if(t1[i] != t2[i]){
                    t1[m[t2[i]]] = t1[i];
                    m[t1[i]] = m[t2[i]];
                    m[t2[i]] = i;
                    t1[i] = t2[i];
                    ct++;
                }
            }
            t1.clear(); t2.clear(); m.clear();
        }
        return ct;
    }
};