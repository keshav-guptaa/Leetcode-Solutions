class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib;
        fib.push_back(1);
        int curr = 1, prev = 0;
        while(curr < INT_MAX - prev){
            fib.push_back(curr+prev);
            prev = curr;
            curr = fib.back();
        }
        //for(auto &x: fib) cout << x << " ";
        int ct = 0;
        while(k){
            ct++;
            int idx = lower_bound(fib.begin(), fib.end(), k) - fib.begin();
            if(fib[idx] == k) break;
            else idx--;
            k -= fib[idx];
        }
        return ct;
    }
};