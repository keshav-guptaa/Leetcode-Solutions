class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int y = x;
        long z = 0;
        while(x){
            z = z*10 + x%10;
            x /= 10;
        }
        return y == int(z);
    }
};