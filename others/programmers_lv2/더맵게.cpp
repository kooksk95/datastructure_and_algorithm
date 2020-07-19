#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> q;
    for(int x : scoville) q.push(x);
    
    int answer = 0, k;
    while(q.top() < K){
        if(q.size()<2) return -1;
        
        answer++;
        k = q.top(); q.pop();
        k += q.top()*2; q.pop();
        q.push(k);
    }
    return answer;
}