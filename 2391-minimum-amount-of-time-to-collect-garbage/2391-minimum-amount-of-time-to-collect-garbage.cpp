class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ctm = 0, ctp = 0, ctg = 0, l1 = 0, l2 = 0, l3 = 0, idx = 0;
        for(auto &s: garbage){
            for(auto &it: s){
                if(it == 'G'){
                    ctg++;
                    l1 = idx;
                } 
                else if(it == 'P'){
                    ctp++;
                    l2 = idx;
                } 
                else{
                    ctm++;
                    l3 = idx;
                } 
            }
            idx++;
        }
        int ans = ctm + ctp + ctg, sum = 0;
        for(int i = 0; i < travel.size(); i++){
            sum += travel[i];
            if(i+1 == l1) ans += sum;
            if(i+1 == l2) ans += sum;
            if(i+1 == l3) ans += sum;
        }
        return ans;
    }
};