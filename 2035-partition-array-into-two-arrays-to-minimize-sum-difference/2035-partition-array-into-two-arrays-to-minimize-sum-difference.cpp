class Solution {
public:
    int minimumDifference(vector<int>& arr) {
        int N = arr.size(), n = N/2;
        vector<vector<int>> left(n+1), right(n+1);
        int tot = accumulate(arr.begin(), arr.end(), 0);
        
        for(int mask = 1; mask < (1 << n); mask++){
            int sz = 0, l = 0, r = 0;
            for(int i = 0; i < n; i++){
                if(mask & (1 << i)){
                    sz++;
                    l += arr[i];
                    r += arr[i+n];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }
        
        for(int sz = 0; sz <= n; sz++) sort(right[sz].begin(), right[sz].end());
        
        int ans = min(abs(tot-2*left[n][0]), abs(tot-2*right[n][0]));
        for(int sz = 1; sz < n; sz++){
            for(int i = 0; i < left[sz].size(); i++){
                int s1 = left[sz][i];
                int s2 = (tot - 2*s1)/2, rsz = n-sz;
                auto &v = right[rsz];
                
                auto it = lower_bound(v.begin(), v.end(), s2);
                
                if(it != v.end()) ans = min(ans, abs(tot - 2*(s1 + (*it))));
                if(it != v.begin()) ans = min(ans, abs(tot - 2*(s1 + (*(--it)))));
                
            }
        }
        return ans;
    }
};