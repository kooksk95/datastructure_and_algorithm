#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    int answer = 0;
    for(int x : d){
        budget -= x;
        if(budget < 0) break;
        answer++;
    }
    
    return answer;
}