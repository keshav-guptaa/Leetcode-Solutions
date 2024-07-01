class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size(), ct = 0;
        for(int i = 0; i < n; i++){
            if(arr[i]&1) ct++;
            else ct = 0;
            if(ct == 3) return true;
        }
        return false;
    }
};