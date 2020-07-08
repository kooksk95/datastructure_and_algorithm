#include <bits/stdc++.h>
using namespace std;
#define MX 20001
#define REP(i,a,b) for(auto i=a; i<b; i++)
#define ENT cout << "\n";

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int F,S,G,U,D;
	cin>>F>>S>>G>>U>>D;

	int dist[F+1] = {};
	queue<int> q;
	dist[S] = 1;
	q.push(S);
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		if(curr == G) break;

		if(curr+U <= F && !dist[curr+U]){
			dist[curr+U] = dist[curr] + 1;
			q.push(curr+U);
		}
		if (curr-D>0 && !dist[curr-D]){
			dist[curr-D] = dist[curr] + 1;
			q.push(curr-D);
		}
	}

	if(dist[G]) cout << dist[G]-1;
	else cout << "use the stairs";

	return 0;
}