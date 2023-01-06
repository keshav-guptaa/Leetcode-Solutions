class Solution {
public:
    bool isPossible(vector<int>& dist, int mid, double hour){
        double hrs = 0;
        int n = dist.size();
        for(int i = 0; i < n; i++){
            if(i == n-1){
                hrs += double(dist[i])/mid;
            }
            else hrs += ceil(double(dist[i])/mid);
        }
        return hrs <= hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        //int sum = accumulate(dist.begin(), dist.end(), 0);
        int s = 1, ans = -1;
        int e = 1e9;
        int mid = s + (e-s)/2;
        while(s <= e){
            if(isPossible(dist, mid, hour)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};