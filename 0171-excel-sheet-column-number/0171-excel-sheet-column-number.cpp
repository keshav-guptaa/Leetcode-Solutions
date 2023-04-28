class Solution {
public:
    int titleToNumber(string cT) {
        int ans = 0;
        for(int i = 0; i < cT.length(); i++){
            ans = ans*26 + (cT[i]-'A') + 1;
        }
        return ans;
    }
};