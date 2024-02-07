class Solution {
public:
    static const int N = 1e5+5;
    int seg[4*N];
    
    void update(int idx, int low, int high, int node, int val){
        if(low == high) seg[idx] = val;
        else{
            int mid = (low + high) >> 1;
            if(node >= low && node <= mid) update(2*idx+1, low, mid, node, val);
            else update(2*idx+2, mid+1, high, node, val);
            seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
        }
    }
    
    int query(int idx, int low, int high, int l, int r){
        if(low >= l && high <= r) return seg[idx];
        if(low > r || high < l) return 0;
        int mid = (low+high)/2;
        int left = query(2*idx+1, low, mid, l, r);
        int right = query(2*idx+2, mid+1, high, l, r);
        return max(left, right);
    }
    
    int lengthOfLIS(vector<int>& nums, int k) {
        int ans = 1;
        update(0, 0, N, nums[0], 1);
        for(int i = 1; i < nums.size(); i++){
            int mx = query(0, 0, N, max(1, nums[i]-k), nums[i]-1);
            update(0, 0, N, nums[i], mx+1);
            ans = max(ans, mx+1);
        }
        return ans;
    }
};