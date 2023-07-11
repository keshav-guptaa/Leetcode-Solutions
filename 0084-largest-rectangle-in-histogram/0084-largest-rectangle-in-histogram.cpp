class Solution {
public:
    int largestRectangleArea(vector<int>& h){
        int n = h.size();
        vector<int> l(n), r(n);
        stack<pair<int, int>> st1, st2;
        for(int i = 0; i < n; i++){
            while(!st1.empty() && st1.top().first >= h[i]) st1.pop();
            if(st1.empty()) l[i] = i;
            else l[i] = i-st1.top().second-1;
            st1.push({h[i], i});
        }
        for(int i = n-1; i >= 0; i--){
            while(!st2.empty() && st2.top().first >= h[i]) st2.pop();
            if(st2.empty()) r[i] = n-i-1;
            else r[i] = st2.top().second-i-1;
            st2.push({h[i], i});
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, (l[i]+r[i]+1)*h[i]);
        }
        return ans;
    }
};