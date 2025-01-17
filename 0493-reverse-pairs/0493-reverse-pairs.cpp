#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
    
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        ordered_set<pair<long long, int>>s;
        for(int i = 0; i < n; ++i){
            s.insert({nums[i], i});
        }
        long long ans = 0;
        for(int i = n-1; i >= 0; --i){
            s.erase({nums[i], i});
            ans += s.size() - s.order_of_key({2*1LL*nums[i] + 1, -1});
        }
        return ans;
    }
};