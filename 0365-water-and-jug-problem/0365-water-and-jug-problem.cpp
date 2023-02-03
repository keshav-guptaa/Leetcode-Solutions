class Solution {
public:
    bool canMeasureWater(int j1, int j2, int goal) {
        if(j1 + j2 < goal) return false;
        return goal%(__gcd(j1, j2)) == 0;
    }
};