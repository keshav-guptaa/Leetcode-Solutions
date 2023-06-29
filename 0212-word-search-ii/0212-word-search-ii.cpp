class TrieNode{
    public:
    TrieNode* next[26];
    string word;
    bool isEnd;
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    
    void insert(string& s){
        TrieNode* node = root;
        for(int i = 0; i < s.length(); i++){
            if(node->next[s[i]-'a'] == NULL){
                node->next[s[i]-'a'] = new TrieNode();
            }
            node = node->next[s[i]-'a'];
        }
        node->isEnd = true;
        node->word = s;
    }
    
    void dfs(int r, int c, TrieNode* node, vector<vector<char>>& b, vector<string>& ans, 
             int n, int m){
        if( r < 0 || c < 0 || r >= n || c >= m || b[r][c] == '*' || 
           !(node->next[b[r][c]-'a']) ) return;
        node = node->next[b[r][c]-'a'];
        
        if(node->isEnd){
            ans.push_back(node->word);
            node->isEnd = false;
        }
        
        char ch = b[r][c];
        b[r][c] = '*';
        dfs(r+1, c, node, b, ans, n, m);
        dfs(r, c+1, node, b, ans, n, m);
        dfs(r-1, c, node, b, ans, n, m);
        dfs(r, c-1, node, b, ans, n, m);
        b[r][c] = ch;
    }
    
    vector<string> findWords(vector<vector<char>>& b, vector<string>& words) {
        for(auto &it: words) insert(it);
        vector<string> ans;
        int n = b.size(), m = b[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dfs(i, j, root, b, ans, n, m);
            }
        }
        return ans;
    }
};