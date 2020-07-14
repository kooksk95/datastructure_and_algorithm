#include <string>
#include <vector>

using namespace std;

int total = 0;
void dfs(vector<int>& n, int pos, int target){
    if(pos == n.size()) {
        if(target == 0) total++;
        return;
    }
    
    dfs(n, pos+1, target+n[pos]);
    dfs(n, pos+1, target-n[pos]);
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, 1, target+numbers[0]);
    dfs(numbers, 1, target-numbers[0]);
    
    return total;
}