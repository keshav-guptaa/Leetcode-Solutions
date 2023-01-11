class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n+1, 1);
        isPrime[0] = isPrime[1] = 0;
        
        int ans = 0;
        for(int i = 2; i < n; i++){
            if(isPrime[i]){
                ans++;
                for(int j=2*i;j<n;j+=i){
                    isPrime[j]=0;
                }
            }
        }
        return ans;
    }
};