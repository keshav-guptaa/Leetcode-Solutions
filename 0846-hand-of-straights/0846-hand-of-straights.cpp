class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        if(hand.size() % gs != 0) return false;
        map<int, int> m;
        for(auto &it: hand) m[it]++;
        while(m.size() > 0){
            int first = m.begin()->first;
            int target = first + gs - 1;
            for(int i = first; i <= target; i++){
                if(m.count(i) == 0) return false;
                else m[i]--;
                if(m[i] == 0) m.erase(i);
            }
        }
        return true;
    }
};