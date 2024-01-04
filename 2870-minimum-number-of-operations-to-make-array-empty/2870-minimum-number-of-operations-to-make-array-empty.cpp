class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto &it: nums) m[it]++;
        int ct = 0;
        for(auto &it: m){
            int z = it.second;
            if(z == 1) return -1;
            if(z%3 == 1){
                z -= 4;
                ct += 2;
                ct += z/3;
            }
            else if(z%3 == 2){
                z -= 2;
                ct++;
                ct += z/3;
            }
            else ct += z/3;
        }
        return ct;
    }
};