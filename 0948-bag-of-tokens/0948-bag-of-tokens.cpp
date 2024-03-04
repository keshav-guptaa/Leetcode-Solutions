class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size(), score = 0, i = 0, j = n-1;
        if(n == 0) return 0;
        
        int mx = 0;
        while(i <= j){
            while(i <= j && power >= tokens[i]){
                power -= tokens[i++];
                score++;
            }
            mx = max(mx, score);
            if(score > 0 && j > i){
                power += tokens[j--];
                score--;
            }
            else break;
        }
        return mx;
    }
};