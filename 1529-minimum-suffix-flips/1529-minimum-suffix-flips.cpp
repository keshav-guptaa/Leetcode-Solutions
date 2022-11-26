class Solution {
public:
    int minFlips(string target) {
        int ans = 0;
        if(target[0] == '1'){
            ans = 1;
        }
        for(int i = target.length() - 1; i >= 1; i--){
            if(target[i] != target[i-1]) ans++;
        }
        return ans;
    }
};