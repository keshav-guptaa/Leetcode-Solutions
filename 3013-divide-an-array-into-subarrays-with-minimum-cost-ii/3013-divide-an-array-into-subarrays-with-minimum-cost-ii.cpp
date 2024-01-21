#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


class Solution {
public: 
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size(), l = dist+1;
        long long sum = 0, ans = 0;
        ordered_set<pair<int, int>> s;
        k--;
        for(int i = 1; i <= l; i++) s.insert({nums[i], i});
        for(int i = 0; i < k; i++) sum += s.find_by_order(i)->first;
        ans = sum;
        
        for(int i = l+1; i < n; i++){
            bool flag = 0;
            if(s.order_of_key({nums[i-l], i-l}) <= k-1){
                sum -= nums[i-l];
                flag = 1;
            }
            s.erase({nums[i-l], i-l});
            s.insert({nums[i], i});
            if(s.order_of_key({nums[i], i}) <= k-1){
                sum += nums[i];
                if(!flag) sum -= s.find_by_order(k)->first;
            }
            else if(flag){
                sum += s.find_by_order(k-1)->first;
            }
            ans = min(sum, ans);
        }
        return nums[0] + ans;
    }
};