class Solution {
public:
    int reverse(int x) {
        bool f = 0;
        if(x < 0){
            f = 1;
            x = abs(x);
        } 
        int z = 0;
        while(x > 0){
            if(z > INT_MAX/10) return 0;
            z *= 10;
            z += (x%10);
            x /= 10;
        }
        return f ? -1*z:z;
    }
};