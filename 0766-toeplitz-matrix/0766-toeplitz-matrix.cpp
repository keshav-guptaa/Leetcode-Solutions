class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int j = 0; j < n; j++){
            int i = 0;
            int k = j;
            int comp = matrix[i][k];
            while(i < m && k < n){
                if(matrix[i][k] != comp) return false;
                i++;
                k++;
            }
        }
        
        for(int j = 0; j < m; j++){
            int i = j;
            int k = 0;
            int comp = matrix[i][k];
            while(i < m && k < n){
                if(matrix[i][k] != comp) return false;
                i++;
                k++;
            }
        }
        return true;
    }
};