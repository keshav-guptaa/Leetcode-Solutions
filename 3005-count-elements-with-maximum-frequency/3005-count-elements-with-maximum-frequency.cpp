class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> m;
        int mx = 0, ct = 0;
        for(auto &it: nums){
            m[it]++;
            if(m[it] > mx){
                mx = m[it];
                ct = 1;
            } 
            else if(m[it] == mx) ct++;
        }
        cout << ct << " " << mx << endl;
        return ct*mx;
    }
};