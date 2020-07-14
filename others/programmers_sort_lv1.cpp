/*
    배열 array, [i, j, k]를 원소로 가진 2차원 배열 commands가 주어질 때
    배열의 subarray [i : j]를 정렬해 k번째에 있는 수를 구하시오.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0; i<commands.size(); i++){
        vector<int> tmp;
        int b = commands[i][0]-1, e = commands[i][1], k = commands[i][2]-1;
        
        tmp.insert(tmp.begin(), array.begin()+b, array.begin()+e);
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp[k]);
    }
    
    return answer;
}