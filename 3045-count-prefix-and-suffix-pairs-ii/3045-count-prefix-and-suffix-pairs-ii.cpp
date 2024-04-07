struct TrieNode{
  public:
    map<pair<char, char>, TrieNode*> next;
    long long ct = 0;
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    
    long long insert(string& s){
        long long ans = 0;
        TrieNode* node = root;
        int n = s.length();
        for(int i = 0; i < n; i++){
            pair<char, char> key = {s[i], s[n-i-1]};
            if(node->next[key] == NULL) node->next[key] = new TrieNode();
            ans += node->ct;
            node = node->next[key];
        }
        ans += node->ct;
        node->ct++;
        return ans;
    }
    
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long ans = 0;
        for(auto& it: words) ans += insert(it);
        return ans;
    }
};