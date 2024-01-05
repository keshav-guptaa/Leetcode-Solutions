class Solution {
public:
    const int mod = 1e9+7;
    int maxSum(vector<int>& n1, vector<int>& n2) {
        int n = n1.size(), m = n2.size(), i = 0, j = 0;
        long long p1 = 0, p2 = 0, ans = 0;
        while(i < n && j < m){
            if(n1[i] < n2[j]) p1 += n1[i++];
            else if(n1[i] > n2[j]) p2 += n2[j++];
            else{
                ans += max(p1 + n1[i++], p2 + n2[j++]);
                p1 = 0, p2 = 0;
                ans %= mod;
            }
        }
        while(i < n) p1 += n1[i++];
        while(j < m) p2 += n2[j++];
        ans += max(p1, p2);
        return ans%mod;
    }
};