class DSU {
    public: 
    vector<int> p, s; 
    DSU(int n){
        p.resize(n+1); s.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            p[i] = i; s[i] = 1; 
        }
    }

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
    bool equationsPossible(vector<string>& eq) {
        DSU ds(26);
        int n = eq.size();
        vector<pair<int, int>> doubt;
        for(int i = 0; i < n; i++){
            if(eq[i][1] == '='){
                ds.merge(eq[i][0]-'a', eq[i][3]-'a');
            }
            else{
                doubt.push_back({eq[i][0]-'a', eq[i][3]-'a'});
            }
        }
        for(int i = 0; i < doubt.size(); i++){
            if(ds.isConnected(doubt[i].first, doubt[i].second)) return false;
        }
        return true;
    }
};