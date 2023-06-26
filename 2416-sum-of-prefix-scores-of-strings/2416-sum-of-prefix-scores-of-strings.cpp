class TrieNode{
  public:
    int cp;
    TrieNode* dict[26] = {};
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    
    void insert(string s){
        TrieNode* node = root;
        for(int i = 0; i < s.length(); i++){
            if(node->dict[s[i]-'a'] == NULL){
                node->dict[s[i]-'a'] = new TrieNode();
            }
            node = node->dict[s[i]-'a'];
            node->cp++;
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    int startsWith(string s) {
        TrieNode* node = root;
        int ans = 0;
        for(int i=0;i<s.length();i++){
            if(node->dict[s[i]-'a'] == NULL) return ans;
            node = node->dict[s[i]-'a'];
            ans += node->cp;
        }
        return ans;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        for(auto &s: words){
            insert(s);
        }
        vector<int> ans;
        for(auto &s: words){
            int x = startsWith(s);
            ans.push_back(x);
        }
        return ans;
    }
};