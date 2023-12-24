class Solution {
public:
int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
    long long ans = -1, mod= 1e9 + 7;
    unordered_set<int> st;
    hFences.push_back(1); hFences.push_back(m); 
    vFences.push_back(1); vFences.push_back(n); 
    for(int i = 0; i < hFences.size(); i++){
        for(int j = i+1; j < hFences.size(); j++){
            st.insert(abs(hFences[i]-hFences[j]));
        }
    }
    for(int i = 0; i < vFences.size(); i++){
        for(int j = i+1; j < vFences.size(); j++){
            long long diff = abs(vFences[i]-vFences[j]);
            if(st.find(diff) != st.end()){
                ans = max(ans, diff);
            }
        }
    }
    return ans == -1 ? ans : (ans*ans)%mod;
}
};