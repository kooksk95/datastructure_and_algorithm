#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, front = 0, back = people.size()-1;
    sort(people.begin(), people.end());
    while(back>=front){
        if(people[back]+people[front]<=limit)
            front++;
        
        back--, answer++;
    }
    
    return answer;
}