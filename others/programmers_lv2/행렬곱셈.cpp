#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int row_size=arr1.size(), col_size=arr2[0].size(), size=arr2.size();
    
    for(int i=0; i<row_size; i++){
        vector<int> row;
        for(int j=0; j<col_size; j++){
            int sum = 0;
            for(int k=0; k<size; k++)
                sum += arr1[i][k]*arr2[k][j];
            
            row.push_back(sum);
        }
        answer.push_back(row);
    }
    return answer;
}