class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ans = 0;
        vector<int> pf(n);
        vector<int> sf(n);
        pf[0] = 1, sf[n-1] = 1;
        int i = 1;
        while(i < n){
            if(ratings[i] > ratings[i-1]){
                pf[i] = pf[i-1] + 1;
            }
            else pf[i] = 1;
            i++;
        }
        i = n-2;
        while(i >= 0){
            if(ratings[i] > ratings[i+1]){
                sf[i] = sf[i+1] + 1;
            }
            else sf[i] = 1;
            i--;
        }
        i = 0;
        while(i < n){
            ans += max(pf[i], sf[i]);
            cout << pf[i] << " " << sf[i] << endl;
            i++;
        }
        return ans;
    }
};