class Solution {
public:
    int mod = 1e9+7;
    int valueAfterKSeconds(int n, int k) {
        vector<int> v(n, 1);
        for(int i = 0; i < k; i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                sum += v[j];
                sum %= mod;
                v[j] = sum;
            }
        }
        return v[n-1];
    }
};