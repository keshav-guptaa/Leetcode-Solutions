class Solution {
public:
    const int mod = 1e9+7;
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long tot = 0, ans = 0, sum = 0;
        for(int i = 1; i <= min(k, 2); i++){
            for(auto &it: arr){
                if(i == 1) tot += it;
                sum += it;
                if(sum < 0) sum = 0;
                ans = max(ans, sum);
            }
        }
        if(tot > 0 && k > 2) ans += tot*(k-2);
        return ans%mod;
    }
};