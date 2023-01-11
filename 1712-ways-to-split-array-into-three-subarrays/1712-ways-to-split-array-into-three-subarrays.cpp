class Solution {
public:
    int stBS(vector<int> &pf, int idx){
        int s = idx+1, e = pf.size()-2;
        int mid = s + (e-s)/2;
        int ans = -1;
        int goal = 2*pf[idx];
        while(s <= e){
            if(pf[mid] >= goal){
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
            mid = s + (e-s)/2;
        }
        return ans;
    }
    
    int endBS(vector<int> &pf, int idx){
        int n = pf.size();
        int s = idx+1, e = n-2;
        int mid = s + (e-s)/2, ans = -1;
        int goal = pf[n-1] + pf[idx];
        while(s <= e){
            if(2*pf[mid] <= goal){
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
            mid = s + (e-s)/2;
        }
        return ans;
    }
    
    int waysToSplit(vector<int>& nums) {
        vector<int> pf = nums;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            pf[i] += pf[i-1];
        }
        //for(int i = 0; i < n; i++) cout << pf[i] << " ";
        int ans = 0;
        int M = 1000000007;
        for(int i = 0; i <= n-1; i++){
            int initial = stBS(pf, i);
            //cout << initial << " ";
            if(initial != -1){
                int last = endBS(pf, i);
                //cout << initial << " ";
                if(last != -1 && initial <= last){
                    //cout << i << " " << last;
                    ans = (ans + last - initial + 1)%M;
                }
            }
        }
        return ans;
    }
};