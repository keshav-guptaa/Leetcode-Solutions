class Solution {
private:
    bool isPalindromic(long long x) {
        long long y = 0LL, z = x;
        while (x > 0) {
            y = 10LL * y + (x % 10LL);
            x /= 10LL;
        }
        return (y == z);
    }
    long long getNextNumber(long long x) {
        while (!isPalindromic(x)) x++;
        return x;
    }
    long long getPrevNumber(long long x) {
        while (!isPalindromic(x)) x--;
        return x;
    }
    long long getCost(vector<int>& nums, long long x) {
        long long cost = 0LL;
        for (auto& num : nums) cost += abs((long long)num - x);
        return cost;
    }
    
public: 
    long long minimumCost(vector<int>& nums) {
        // sort the array
        sort(nums.begin(), nums.end());

        // find the median
        int n = nums.size();
        long long median = (nums[n / 2] + nums[(n - 1) / 2]) / 2;
        
        // if the median is palindromic, it is the best choice
        if (isPalindromic(median)) return getCost(nums, median);

        // try the palindromic numbers that are near to the median
        return min(
            getCost(nums, getNextNumber(median)),
            getCost(nums, getPrevNumber(median))
        );
    }

};