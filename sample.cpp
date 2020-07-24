#include <bits/stdc++.h>
using namespace std;

int main() {
	priority_queue<int> pq;
	pq.push(5);
	pq.push(2);
	pq.push(1);

	pq.top()--;
	pq.top()--;
	pq.top()--;
	pq.top()--;
	pq.top()--;

	for(int x:pq) cout<<pq<<" ";

	return 0;//Your program should return 0 on normal termination.
}