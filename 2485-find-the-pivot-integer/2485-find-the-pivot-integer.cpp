class Solution {
public:
    int pivotInteger(int n) {
        int s = 1, e = n, ans = -1, mid, tot = (n*(n+1))/2;
        
        while(s <= e){
            mid = s + (e-s)/2;
            if(mid*(mid+1) == tot+mid){
                ans = mid;
                break;
            } 
            else if(mid*(mid+1) < tot+mid) s = mid+1;
            else e = mid-1;
        }
        return ans;
    }
};