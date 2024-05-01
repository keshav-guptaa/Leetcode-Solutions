class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto found = word.find(ch);
        if(found == string::npos) return word;
        int i = 0;
        while(i < found){
            swap(word[i], word[found]);
            i++; found--;
        }
        return word;
    }
};