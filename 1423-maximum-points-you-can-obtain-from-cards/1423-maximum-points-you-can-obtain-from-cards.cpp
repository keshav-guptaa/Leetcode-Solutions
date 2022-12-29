class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int count = 0;
        for(int i = 0; i < k; i++){
            count += cardPoints[i];
        }
        int ans = count;
        //cout << ans << endl;
        int j = cardPoints.size()-1;
        int i = k-1;
        while(i >= 0){
            count = count - cardPoints[i] + cardPoints[j];
            ans = max(ans, count);
            i--;
            j--;
            //cout << ans << " ";
        }
        return ans;
    }
};