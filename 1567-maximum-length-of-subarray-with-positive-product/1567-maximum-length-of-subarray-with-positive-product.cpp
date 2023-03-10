class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int mx = 0;  
        int sz = nums.size();
        for(int i = 0; i < sz; i++){     
            int n_s = -1, n_e = -1, n = 0, p = 0, j;

            for(j=i;j<sz;j++){    
                if(nums[j] < 0) n++;
                if(nums[j] > 0) p++;
                if(nums[j] < 0 && n_s == -1){
                      n_s=j;
                } 
                if(nums[j] < 0) n_e = j;             
                if(nums[j] == 0) break;         
            }
             
            if(n%2 == 0) mx = max(mx, n+p);
          
            if(n%2==1){
                mx = max(j-n_s-1, mx);
                mx = max(n_e-i, mx);
            }
            i = j; 
        }
        return mx;
    }
};