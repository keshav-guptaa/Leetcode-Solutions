class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length(), i = 0, j = 0, cost = 0, ans = 0;
        
        while(j < n){
            cost += abs(t[j]-s[j]);
            while(cost > maxCost){
                cost -= abs(t[i]-s[i]);
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};