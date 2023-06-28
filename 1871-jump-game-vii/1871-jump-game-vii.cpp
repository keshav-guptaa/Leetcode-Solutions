class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        queue<int> q;
        q.push(0);
        int farthest = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr == n-1) return true;
            for(int i = max(curr+minJump, farthest+1); i <= min(n-1, curr+maxJump); i++){
                if(s[i] == '0') q.push(i);
            }
            farthest = min(curr+maxJump, n-1);
        }
        return false;
    }
};