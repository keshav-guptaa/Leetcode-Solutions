class Solution {
public:
    int bSearch(vector<long>& pf, int goal){
        int s = 0, e = pf.size()-1;
        int mid = s + (e-s)/2, ans=-1;
        while(s <= e){
            if(pf[mid] > goal) e = mid-1;
            else if(pf[mid] <= goal){
                ans = mid;
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return ans+1;
    }
    
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size(), goal = 0;
        vector<long> pf(n);
        pf[0] = chalk[0];
        for(int i = 1; i < n; i++){
            pf[i] += chalk[i] + pf[i-1];
        }
        goal = k%pf[n-1];
        return bSearch(pf, goal);
    }
};