#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int b, int y) {
    vector<int> answer;
    int add = sqrt(b*b-8*b+16-16*y);
    int ans[2] = {(4+b+add)/4, (4+b-add)/4};
    answer.insert(answer.begin(), ans, ans+2);
    return answer;
}