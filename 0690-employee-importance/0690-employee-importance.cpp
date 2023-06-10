/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, Employee*> m;  // id -> employee
    
    int dfs(int id){
        int ans = 0;
        ans += m[id]->importance;
        for(auto &it: m[id]->subordinates){
            ans += dfs(it);
        }
        return ans;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        for(auto &it: employees) m[it->id] = it;
        return dfs(id);
    }
};