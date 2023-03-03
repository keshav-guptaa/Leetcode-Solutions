class Solution {
public:
    int strStr(string h, string n) {
        if(h.find(n) != string::npos) return h.find(n);
        else return -1;
    }
};