class Solution {
public:
    int maxArea(vector<int>& v) {
        int n = v.size();
        int i = 0, j = n-1, ans = INT_MIN;
        while(i < j){
            ans = max(ans, min(v[i], v[j])*(j-i));
            cout << ans << " ";
            if(v[i] == v[j]){
                i++;
                j--;
            } 
            else if(v[j] < v[i]) j--;
            else i++;
        }
        return ans;
    }
};