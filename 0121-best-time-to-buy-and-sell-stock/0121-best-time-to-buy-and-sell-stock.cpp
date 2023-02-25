class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices.size();
        vector<int> rightMax(l);
        int maxx = INT_MIN;
        for(int i=l-1; i>=0; i--){
            maxx = max(maxx,prices[i]);
            rightMax[i] = maxx;
        }
        maxx = INT_MIN;
        int temp;
        for(int i=0; i<l; i++){
            temp = rightMax[i] - prices[i];
            maxx = max(maxx,temp);
        }
        if(maxx > 0) return maxx;
        else return 0;
    }
};