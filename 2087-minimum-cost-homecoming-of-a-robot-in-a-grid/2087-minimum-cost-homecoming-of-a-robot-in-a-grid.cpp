class Solution {
public:
    int minCost(vector<int>& stP, vector<int>& hP, vector<int>& rC, vector<int>& cC) {
        int cost = 0;
        if(stP[0] < hP[0]){
            for(int i = stP[0]+1; i <= hP[0]; i++){
                cost += rC[i];
            }
        }
        else{
            for(int i = stP[0]-1; i >= hP[0]; i--){
                cost += rC[i];
            }
        }
        
        if(stP[1] < hP[1]){
            for(int i = stP[1]+1; i <= hP[1]; i++){
                cost += cC[i];
            }
        }
        else{
            for(int i = stP[1]-1; i >= hP[1]; i--){
                cost += cC[i];
            }
        }
        return cost;
    }
};