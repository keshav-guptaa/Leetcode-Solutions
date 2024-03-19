class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> m;
        for(auto &it: tasks) m[it]++;
        //time, char
        priority_queue<pair<int, char>> pq;
        for(char ch = 'A'; ch <= 'Z'; ch++){
            if(m[ch] != 0) pq.push({0, ch});
        }
        int ans = 0;
        while(!pq.empty()){
            auto [time, ch] = pq.top();
            time = abs(time);
            pq.pop();
            m[ch]--;
            if(time <= ans) ans++;
            else ans = time+1;
            if(m[ch] != 0) pq.push({-(time+n+1), ch});
        }
        return ans;
    }
};