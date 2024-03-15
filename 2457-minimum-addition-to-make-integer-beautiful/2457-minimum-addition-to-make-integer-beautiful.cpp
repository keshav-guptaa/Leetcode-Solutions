class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        int sum = 0;
        long long t = n, ans = 0;
        while(t){
            sum += t%10;
            t /= 10;
        }
        
        long long mul = 1, carry = 0;
        
        while(sum > target){
            int digit = n%10 + carry;
            if(digit != 0){
                carry = 1;
                ans += (10 - digit)*mul;
                sum -= --digit;
            }
            else carry = 0;
            n /= 10;
            mul *= 10;
        }
        return ans;
    }
};