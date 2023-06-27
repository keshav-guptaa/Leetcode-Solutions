class TrieNode{
    public:
    bool isEnd = false;
    TrieNode* next[26];
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.length(); i++){
            if(node->next[word[i]-'a'] == NULL){
                node->next[word[i]-'a'] = new TrieNode();
            }
            node = node->next[word[i]-'a'];
        }
        node->isEnd = true;
    }
    
    bool f(TrieNode* node, string word, int idx){
        if(idx == word.length()){
            return node->isEnd;
        }
        
        if(word[idx] == '.'){
            for(int i = 0; i < 26; i++){
                if(node->next[i] == NULL) continue;
                else{
                    if(f(node->next[i], word, idx+1)) return true;
                }
            }
        }
        else{
            if(node->next[word[idx]-'a'] == NULL) return false;
            return f(node->next[word[idx]-'a'], word, idx+1);
        }
        return false;
    }
    
    
    bool search(string word) {
        TrieNode* node = root;
        return f(node, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */