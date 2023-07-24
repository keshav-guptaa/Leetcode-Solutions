class Solution {
public:
    int longestSubsequence(vector<int>& arr, int dif) {
        unordered_map<int, int> m;
        int mx = 0;
        for(int i = 0; i < arr.size(); i++){
            if(m[arr[i]-dif] != 0) m[arr[i]] = max(m[arr[i]], m[arr[i]-dif] + 1);
            else m[arr[i]] = max(m[arr[i]], 1);
            mx = max(mx, m[arr[i]]);
        }
        return mx;
    }
};