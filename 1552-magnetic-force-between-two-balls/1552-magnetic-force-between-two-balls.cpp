class Solution {
public:
    bool isPossible(vector<int>& position, int mid, int m){
        int balls = 1;
        int lastPos = position[0];
        for(int i = 1; i < position.size(); i++){
            if(position[i] - lastPos >= mid){
                balls++;
                lastPos = position[i];
                if(balls == m) return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int s = 1, e = position[n-1];
        int mid = s + (e-s)/2, ans;
        while(s <= e){
            if(isPossible(position, mid, m)){
                ans = mid;
                s = mid+1;
            }
            else e = mid - 1;
            mid = s + (e-s)/2;
        }
        return ans;
    }
};