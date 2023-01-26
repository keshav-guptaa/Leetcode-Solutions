class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int mx = 0, chunks = 0;
        for(auto i = 0; i < arr.size(); i++) {
            mx = max(mx, arr[i]);
            if (mx == i) chunks++;
        }
        return chunks;
    }
};