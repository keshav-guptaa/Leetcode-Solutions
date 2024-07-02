class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> m;
        for(auto& it: nums1) m[it]++;
        for(auto& it: nums2){
            m[it]--;
            if(m[it] >= 0) ans.push_back(it);
        }
        return ans;
    }
};