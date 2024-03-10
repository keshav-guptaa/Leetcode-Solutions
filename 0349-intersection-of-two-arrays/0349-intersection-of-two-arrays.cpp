const int N = 1e3 + 10;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool a[N]={0};
        for(auto &x: nums1){
            a[x]=1;
        }
        vector<int> ans;
        for(auto &x: nums2){
            if(a[x]==1){
                a[x]=0;
                ans.push_back(x);
            }
        }
        return ans;
    }
};