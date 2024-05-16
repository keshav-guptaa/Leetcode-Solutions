class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](vector<int>& a,vector<int>& b){
            return a[1] < b[1];
        });
        
        bool used[2005] = {};       
        int count = 0;
        for(auto& task: tasks){
            int start = task[0], end = task[1], duration = task[2];
            //If some time of current interval used in previous task then current task can also be done in this interval because computer can do unlimited tasks at the same time and it also minimizes the time for which computer is on.
            for(int i = start; i <= end; i++){
                if(used[i]) duration--;
            }
            //I will try to complete the task at the end of allowed range because it may overlap with some other tasks starting range and hence reduces our time for which computer is on.
            for(int i = end; duration > 0; i--){
                if(used[i]) continue;
                duration--;
                used[i] = true;
                count++;
            }
        }
        return count;
    }
};