struct TrieNode{
    TrieNode* bits[2];  
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    
    void insert(int num){
        TrieNode* node = root;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(node->bits[bit] == NULL){
                node->bits[bit] = new TrieNode();
            }
            node = node->bits[bit];
        }
    }
    
    int getMax(int num){
        TrieNode* node = root;
        int maxNum = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(node->bits[1-bit] != NULL){
                maxNum |= (1 << i);
                node = node->bits[1-bit];
            } 
            else node = node->bits[bit];
        }
        return maxNum;
    }
    
    
    int findMaximumXOR(vector<int>& nums) {
        for(auto &it: nums) insert(it);
        int mx = 0;
        for(auto &it: nums) mx = max(mx, getMax(it));
        return mx;
    }
};