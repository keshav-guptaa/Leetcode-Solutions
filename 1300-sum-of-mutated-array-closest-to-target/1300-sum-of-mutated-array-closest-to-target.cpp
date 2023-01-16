class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> pf(n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            pf[i] = sum;
            sum += arr[i];
        }
        int ans;
        int s = 0, e = arr[n-1];
        int mid, dif = INT_MAX, d;
        while(s <= e){
            mid = s + (e-s)/2;
            int idx = lower_bound(arr.begin(), arr.end(), mid) - arr.begin();   
            int sum = pf[idx] + (n-idx)*mid;
            if(sum == target){
                dif = min(dif, 0);
                ans = mid;
                e = mid-1;
            }
            else if(sum < target){
                if(d > target - sum){
                    d = target - sum;
                    ans = mid;
                }
                else if(d == target - sum){
                    ans = min(mid, ans);
                }
                s = mid+1;
            }
            else{
                if(d > sum - target){
                    d = sum - target;
                    ans = mid;
                }
                else if(d == target - sum){
                    ans = min(mid, ans);
                }
                e = mid-1;
            }
        }
        return ans;
    }
};