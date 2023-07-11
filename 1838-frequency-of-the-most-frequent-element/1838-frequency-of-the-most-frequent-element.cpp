class Solution {
public:
    int maxFrequency(vector<int>& A, int k) {
        sort(begin(A), end(A));
        long i = 0, N = A.size(), ans = 1, sum = 0, j = 0;
        while(j < N) {
            sum += A[j];
            //what is required - what we have sould be less than equal to max operations
            while (((j-i+1) * A[j]) - sum > k) sum -= A[i++];
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};