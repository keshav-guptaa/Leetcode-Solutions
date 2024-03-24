struct TrieNode{
  public:
    int smallest = 1e4;
    int idx = 1e6;
    TrieNode* dict[26] = {};
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    
    void insert(string s, int id){
        TrieNode* node = root;
        
        
        for(int i = 0; i < s.length(); i++){
            if(node->dict[s[i]-'a'] == NULL){
                node->dict[s[i]-'a'] = new TrieNode();
            }
            if(s.length() < node->smallest){
                node->smallest = s.length();
                node->idx = id;
            }
            else if(s.length() == node->smallest) node->idx = min(node->idx, id);
            node = node->dict[s[i]-'a'];
        }
        if(s.length() < node->smallest){
                node->smallest = s.length();
                node->idx = id;
        }
        else if(s.length() == node->smallest) node->idx = min(node->idx, id);
    }
    
    int startsWith(string s) {
        TrieNode* node = root;
        for(int i=0;i<s.length();i++){
            if(node->dict[s[i]-'a'] == NULL) return node->idx;
            node = node->dict[s[i]-'a'];
        }
        cout << node->smallest << endl;
        return node->idx;
    }
    
    vector<int> stringIndices(vector<string>& wc, vector<string>& wq) {
        //int idx = 1e6, smallest = 1e4;
        for(int i = 0; i < wc.size(); i++){
            reverse(wc[i].begin(), wc[i].end());
            insert(wc[i], i);
        } 
        //root->idx = idx; 
        int n = wq.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            reverse(wq[i].begin(), wq[i].end());
            ans[i] = startsWith(wq[i]);
        }
        return ans;
    }
};