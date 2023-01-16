class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int s = 0, e = price.back()-price.front();
        int mid, cnt, ans;
        while(s <= e){
            mid = s + (e-s)/2, cnt = 1;
            for(int i = 1, j = 0; i < price.size(); i++){
                if(price[i] - price[j] >= mid){
                    cnt++;
                    j = i;
                }
            }
            if(cnt >= k){
                ans = mid;
                s = mid+1;
            } 
            else e = mid-1;
        }
        return ans;
    }
};