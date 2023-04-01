#define ll   long long
class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        ll n = arr.size(), ans = 0;
        
        for(int i = 0; i < n; i++){
            vector<int> same;
            for(int j = i; arr[j] != 0; j = (j+k)%n){
                same.push_back(arr[j]);
                arr[j] = 0;
            }
            nth_element(same.begin(), same.begin()+same.size()/2, same.end());
            for(auto it: same){
                ans += abs(it-same[same.size()/2]);
            }
        }
        
        return ans;
    }
};