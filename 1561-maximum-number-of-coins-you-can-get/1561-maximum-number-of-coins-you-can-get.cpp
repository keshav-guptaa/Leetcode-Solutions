class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int x = piles.size();
        int z = x - 2;
        x /= 3;
        int ans = 0;
        while(x--){
            ans += piles[z];
            z -= 2;
        }
        return ans;
    }
};