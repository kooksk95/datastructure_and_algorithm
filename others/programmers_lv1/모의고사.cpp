#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    int cnt[3] = {};
    int a[5]={1,2,3,4,5}, b[8]={2,1,2,3,2,4,2,5}, c[10]={3,3,1,1,2,2,4,4,5,5};
    for(int i=0; i<answers.size(); i++){
        if(answers[i] == a[i%5]) cnt[0]++;
        if(answers[i] == b[i%8]) cnt[1]++;
        if(answers[i] == c[i%10]) cnt[2]++;
    }
    
    int mx = *max_element(cnt, cnt+3);
    vector<int> answer;
    for(int i=0; i<3; i++)
        if(cnt[i] == mx) answer.push_back(i+1);
    
    return answer;
}