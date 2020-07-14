/*
    1. 가장 앞에 있는 문서(J)를 꺼냅니다.
    2. 나머지 대기목록에서 J보다 중요도가 높은 문서가 한 개라도 존재하면 J를 대기목록의 가장 마지막에 넣습니다.
    3. 그렇지 않으면 J를 인쇄합니다.
    예를 들어, (A, B, C, D)가 순서대로 인쇄 대기목록에 있고 중요도가 2 1 3 2 라면 C D A B 순으로 인쇄하게 됩니다.
    문서의 중요도 priorities와 내가 인쇄를 요청한 문서의 현재 대기목록 위치를 알려주는 location이 주어질 때,
    내가 인쇄를 요청한 문서가 몇 번째로 인쇄되는지 return 하도록 solution 함수를 작성해주세요.
*/
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    vector<int> sorted(priorities);
    sort(sorted.begin(), sorted.end(), greater<int>());
    
    int pos = 0, print = 0, s = priorities.size();
    while(1){
        if(sorted[print] == priorities[pos]){
            print++;
            if(pos == location) break;
        }
        pos++;
        pos %= s;   
    }
    
    return print;
}