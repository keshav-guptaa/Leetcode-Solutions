class Solution {
public:
TreeNode* reverseOddLevels(TreeNode* root) {
//      level Order Traversal
    queue<TreeNode*> q;
    q.push(root);
    bool reverse = false;
    while(!q.empty()){
        int size = q.size();
        vector<TreeNode*> level;
        for(int i =0;i< size;i++){
            TreeNode* node = q.front();
            q.pop();
            if(node -> left)
                q.push(node -> left);
            if(node -> right)
                q.push(node -> right);
            level.push_back(node);
        }
//          Swap the values of odd level
        if(reverse){
            int l =0, r = level.size()-1;
            while(l<r){
                swap(level[l] -> val, level[r]-> val);
                l++; r--;
            }
            reverse = false;
        }
        else{
            reverse = true;
        }
    } 
    return root;
   }
};