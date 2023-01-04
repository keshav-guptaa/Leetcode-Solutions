class Solution {
public:
    bool isPossible(vector<int>& piles, long mid, int h){
        int req = 0;
        for(auto x: piles){
            req += x/mid + 1;
            if(x % mid == 0) req--;
        }
        return req <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        long sum = 0;
        for(auto x: piles) sum += x;
        long s = sum/h + 1;
        if(sum % h == 0) s--;
        long e = *max_element(piles.begin(), piles.end());
        long mid = s + (e-s)/2;
        while(s < e){
            if(isPossible(piles, mid, h)){
                e = mid;
            }
            else s = mid+1;
            mid = s + (e-s)/2;
        }
        return int(s);
    }
};