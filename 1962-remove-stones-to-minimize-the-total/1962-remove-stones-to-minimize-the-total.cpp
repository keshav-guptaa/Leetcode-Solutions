class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> finder;
        int n = piles.size();
        for(int i = 0; i < n; i++){
            finder.push(piles[i]);
        }
        while(k--){
            int temp = finder.top();
            finder.pop();
            temp = ceil(float(temp)/2);
            finder.push(temp);
        }
        int ans = 0;
        while(!finder.empty()){
            ans += finder.top();
            finder.pop();
        }
        return ans;
    }
};