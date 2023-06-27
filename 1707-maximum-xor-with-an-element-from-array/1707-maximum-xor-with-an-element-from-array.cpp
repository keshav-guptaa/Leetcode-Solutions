struct TrieNode{
    TrieNode* bits[2] = {};  
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
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size(), m = q.size();
        sort(nums.begin(), nums.end());
        vector<tuple<int, int, int>> oQ;
        for(int i = 0; i < m; i++){
            oQ.push_back({q[i][1], q[i][0], i});
        }
        sort(oQ.begin(), oQ.end());
        int idx = 0;
        vector<int> ans(m);
        for(int i = 0; i < m; i++){
            auto [mx, num, aidx] = oQ[i];
            while(idx < n && nums[idx] <= mx){
                insert(nums[idx++]);
            }
            if(idx == 0) ans[aidx] = -1;
            else ans[aidx] = getMax(num);
        }
        return ans;
    }
};