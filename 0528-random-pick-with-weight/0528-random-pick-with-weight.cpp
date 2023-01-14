class Solution {
public:
    vector<int> s;
    Solution(vector<int>& w) {
        s = w;
        for(int i = 1; i < w.size(); i++){
            s[i] += s[i-1];
        }
    }
    
    int pickIndex() {
        int x = s.back();
        int num = rand() % x;
        auto it = upper_bound(s.begin(), s.end(), num);
        return it - s.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */