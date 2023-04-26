class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return num;
        int x = num%9;
        return x == 0 ? 9 : x;
    }
};