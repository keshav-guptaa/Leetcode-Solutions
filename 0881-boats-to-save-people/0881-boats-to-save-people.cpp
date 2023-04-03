class Solution {
public:
    int numRescueBoats(vector<int>& p, int l) {
        sort(p.begin(), p.end());
        int n = p.size();
        int i = 0, j = n-1, ans = 0;
        while(i <= j){
            ans++;
            if(p[i] + p[j] <= l){
                i++;
                j--;
            }
            else{
                j--;
            }
        }
        return ans;
        
    }
};