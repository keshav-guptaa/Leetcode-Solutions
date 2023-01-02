class Solution {
public:
    int minimumPartition(string s, int k) {
        long long num = 0, n = s.length(), ans = 1;
        for(int i = 0; i < n; i++){
            num = num*10 + s[i] - '0';
            if(num > k){
                ans++;
                num = s[i] - '0';
            }
            if(num > k){
                return -1;
            }
        }
        return ans;
    }
};