class Solution {
public:
    double binaryExp(double x, long long n) {
        // Base case, to stop recursive calls.
        if (n == 0) {
            return 1;
        }
       
        // Handle case where, n < 0.
        if (n < 0) {
            return 1.0 / binaryExp(x, -1 * n);
        }
       
        // Perform Binary Exponentiation.
        // If 'n' is odd we perform Binary Exponentiation on 'n - 1' and multiply result with 'x'.
        if (n % 2 == 1) {
            double z = binaryExp(x, n/2);
            return z*x*z ;
        }
        // Otherwise we calculate result by performing Binary Exponentiation on 'n'.
        else {
            double z = binaryExp(x, n / 2);
            return z*z;
        }
    }

    double myPow(double x, int n) {
        return binaryExp(x, (long long) n);
    }
};