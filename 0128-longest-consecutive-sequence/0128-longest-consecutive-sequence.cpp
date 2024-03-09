class DSU {
    public: 
    vector<int> p, s; 
    int ans = 0;
    DSU(int n){
        p.resize(n+1); s.resize(n+1); 
        for(int i = 0; i <= n; i++) {
            p[i] = i; s[i] = 1; 
        }
    }
    //path compression
    int find(int u){
        if(u == p[u]) return u;
        return p[u] = find(p[u]);
    }

    bool isConnected(int u, int v){
        return find(u) == find(v);
    }
    
    void merge(int u, int v){
        int p_u = find(u), p_v = find(v); 
        if(p_u == p_v) return;
        if(s[p_v] > s[p_u]) swap(p_u, p_v);
        p[p_v] = p_u;
        s[p_u] += s[p_v]; 
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        DSU ds(n);
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            if(m[nums[i]] != 0) continue;
            if(m[nums[i]-1] != 0) ds.merge(i+1, m[nums[i]-1]);
            if(m[nums[i]+1] != 0) ds.merge(i+1, m[nums[i]+1]);
            m[nums[i]]= i+1;
        } 
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(ds.p[i] == i && ds.s[i] > ans) ans = ds.s[i];
        }
        return ans;
    }
};