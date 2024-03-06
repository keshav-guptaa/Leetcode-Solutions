class Solution { 
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n, 0), rightMax(n, 0);
        int h = 0;
        for(int i = 0; i < n; ++i){
            leftMax[i] = h;
            h = max(h, height[i]);
        }
        h = 0;
        for (int i = n-1; i >= 0; --i){
            rightMax[i] = h;
            h = max(h, height[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int waterLevel = min(leftMax[i], rightMax[i]);
            if(waterLevel >= height[i]) ans += waterLevel - height[i];
        }
        return ans;
    }
};