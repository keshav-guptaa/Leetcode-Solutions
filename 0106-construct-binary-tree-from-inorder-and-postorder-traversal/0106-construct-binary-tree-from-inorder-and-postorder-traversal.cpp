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
    TreeNode* build(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe){
        if(is > ie || ps > pe) return NULL;
        TreeNode* newNode = new TreeNode(postorder[pe]);
        int pivot = is;
        while(inorder[pivot] != newNode -> val) pivot++;
        int numsLeft = pivot - is;
        
        newNode -> left = build(inorder, is, pivot-1, postorder, ps,                                   ps+numsLeft-1);
        newNode -> right = build(inorder, pivot+1, ie, postorder,                                      ps+numsLeft, pe-1);
        return newNode;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //if(inorder.size() != postorder.size()) return NULL;
        
        //int rootidx = inorder.size()-1;
        return build(inorder, 0, inorder.size()-1, postorder, 0,                            postorder.size()-1);
    }
};