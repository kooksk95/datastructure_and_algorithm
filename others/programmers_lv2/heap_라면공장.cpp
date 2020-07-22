#include <bits/stdc++.h>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0, i=0;
    priority_queue<int> pq; // -supply, date
    while(stock<k){
    	while(i<dates.size() && dates[i]<=stock)
        	pq.push(supplies[i++]);
        
        stock += pq.top();
        pq.pop();
        answer++;
    }
    return answer;
}