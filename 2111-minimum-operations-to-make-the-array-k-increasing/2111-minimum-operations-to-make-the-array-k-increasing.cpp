class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int ans = 0, n = arr.size();
        for(int i = 0; i < k; i++){
            vector<int> lis;
            for(int j = i; j < n; j += k){
                if(lis.empty() || lis.back() <= arr[j]) lis.push_back(arr[j]);
                else{
                    int idx = upper_bound(lis.begin(), lis.end(), arr[j]) - lis.begin();
                    lis[idx] = arr[j];
                }
            }
            ans += lis.size();
        }
        return n-ans;
    }
};