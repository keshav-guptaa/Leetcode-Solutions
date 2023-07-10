struct TrieNode{
    TrieNode* bits[2] = {}; 
    int ct = 0;
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    
    void insert(int num){
        TrieNode* node = root;
        for(int i = 15; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(node->bits[bit] == NULL){
                node->bits[bit] = new TrieNode();
            }
            node = node->bits[bit];
            node->ct++;
        }
    }
    
    int getPairs(int n, int k){
        TrieNode* node = root;
        int ct = 0;
        
        for(int i = 15; i >= 0; i--){
            int bit_n = (n >> i) & 1;
            int bit_k = (k >> i) & 1;
            
            //if bit of k is set
            if(bit_k){
                //bit of n is set
                if(node->bits[bit_n]){
                    ct += node->bits[bit_n]->ct;
                }
                
                if(node->bits[1-bit_n]){
                    node = node->bits[1-bit_n];
                }
                else break;
            }
            else if(node->bits[bit_n]){
                node = node->bits[bit_n];
            }
            else break;
        }
        return ct;
    }
    
    int countPairs(vector<int>& nums, int low, int high) {
        int n = nums.size(), ct = 0;
        for(int i = 0; i < n; i++){
            ct += getPairs(nums[i], high+1);
            ct -= getPairs(nums[i], low);
            insert(nums[i]);
        }
        return ct;
    }
};