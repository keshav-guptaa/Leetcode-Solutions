class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int lastCol = matrix[0].size() - 1;
        int lastRow = matrix.size() - 1;
        int firstRow = 0;
        int firstCol = 0;
        int count = 0;
        int total = (lastCol+1)*(lastRow+1);
        vector<int> ans;
        while(count < total){
            //firstRow
            for(int i=firstCol;count<total && i<=lastCol; i++){
                ans.push_back(matrix[firstRow][i]);
                count++;
            }
            firstRow++;
            //lastCol
            for(int i=firstRow;count<total && i<=lastRow; i++){
                ans.push_back(matrix[i][lastCol]);
                count++;
            }
            lastCol--;
            for(int i=lastCol;count<total && i>=firstCol; i--){
                ans.push_back(matrix[lastRow][i]);
                count++;
            }
            lastRow--;
            for(int i=lastRow;count<total && i>=firstRow; i--){
                ans.push_back(matrix[i][firstCol]);
                count++;
            }
            firstCol++;
        }
        return ans;
    }
        
};