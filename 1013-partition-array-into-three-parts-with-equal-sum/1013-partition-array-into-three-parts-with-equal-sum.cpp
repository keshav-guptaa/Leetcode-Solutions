class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for(int i = 0; i < arr.size(); i++) sum += arr[i];
        if(sum%3 != 0) return false;
        int x = 0;
        int t = 0;
        for(int i = 0; i < arr.size(); i++){
            t += arr[i];
            if(t == sum/3){
                t = 0; x++;
            }
        }
        return x >= 3;
    }
};