class Solution {
public:
    vector<int> peakTree, a;  
    // Helper function to determine if an element is a peak
    bool isPeak(int i, vector<int>& nums) {
        int n = nums.size();
        // Boundary elements can't be peaks
        if (i <= 0 || i >= n - 1) return false;  
        return nums[i] > nums[i - 1] && nums[i] > nums[i + 1];
    }

    // Build the segment tree to count peaks
    void buildTree(int node, int st, int en, vector<int>& nums) {
        if (st == en) {  
            peakTree[node] = isPeak(st,nums) ? 1 : 0;  
            return;
        }
        int mid = (st + en) / 2;
        buildTree(2 * node, st, mid, nums);  
        buildTree(2 * node + 1, mid + 1, en, nums);  
        peakTree[node] = peakTree[2 * node] + peakTree[2 * node + 1];  
    }

    // Query the segment tree to count peaks in range [l, r]
    int query(int node, int st, int en, int l, int r) {
        if (st > r || en < l) return 0;  
        if (st >= l && en <= r) return peakTree[node];  
        int mid = (st + en) / 2;
        int q1 = query(2 * node, st, mid, l, r);
        int q2 = query(2 * node + 1, mid + 1, en, l, r);
        return q1 + q2;  
    }

    // Update the segment tree when an element is changed
    void update(int node, int st, int en, int idx, vector<int>& nums) {
        if (st == en) {  
            peakTree[node] = isPeak(st, nums) ? 1 : 0; 
            return;
        }
        int mid = (st + en) / 2;
        if (idx <= mid) update(2 * node, st, mid, idx, nums);  
        else update(2 * node + 1, mid + 1, en, idx, nums);  
        peakTree[node] = peakTree[2 * node] + peakTree[2 * node + 1];  
    }

    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        a = nums;  
        peakTree.resize(4 * n, 0);  
        
        // Build segment tree to count peaks
        buildTree(1, 0, n - 1, nums);  
        
        vector<int> ans;  
        for (auto& q : queries) {
            if (q[0] == 1) {  
                int l = q[1], r = q[2];
                ans.push_back(query(1, 0, n - 1, l + 1, r - 1));  
            } 
            else {
                int idx = q[1], val = q[2];
                a[idx] = val;  
                if (idx > 0) update(1, 0, n - 1, idx - 1, a); 
                update(1, 0, n - 1, idx, a); 
                if (idx < n - 1) update(1, 0, n - 1, idx + 1, a); 
            }
        }
        return ans;  // Return vector of answers for queries
    }
};
