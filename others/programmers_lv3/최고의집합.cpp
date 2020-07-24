#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int el = s/n;
    if(el == 0) return {-1};
    
    int k = n-s%n;
    while(k--)
        answer.emplace_back(el);
    k = s%n;
    while(k--)
        answer.emplace_back(el+1);
    
    return answer;
}