class Solution {
public:
    
    int countHousePlacements(int n) {
        int placed = 0, empty = 1, res = 1, mod = 1000000007;
        for (int i = 1; i <= n; ++i) {
            placed = empty;
            empty = res;
            res = (placed + empty) % mod;
        }
        return ((long long)res * res) % mod;
    }
};