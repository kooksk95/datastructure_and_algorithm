#include <bits/stdc++.h>
using namespace std;
#define MX 10001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define ENT cout<<"\n";
#define REP(i,a,b) for(auto i=a; i<b; i++)
typedef vector<int> vi;
typedef pair<int,int> pi;

int n, dist[MX];
bool visited[MX];

bool can_convert(int a, int b){
	bool d1 = a%10 ^ b%10;
	a /= 10; b/= 10;
	bool d2 = a%10 ^ b%10;
	a /= 10; b/= 10;
	bool d3 = a%10 ^ b%10;
	a /= 10; b/= 10;
	bool d4 = a ^ b;

	int dist = d1+d2+d3+d4;
	return (dist<2);
}

int main(){

	IOS
	int T; cin>>T;

	// Get prime numbers
	set<int> prime;
	bool not_prime[MX] = {0};
	REP(i,2,MX){
		if(!not_prime[i]){
			if(i>1000) prime.insert(i);

			for(int j=2*i; j<MX; j+=i)
				not_prime[j] = 1;
		}
	}

	while(T--){
		memset(visited, 0, sizeof(visited));
		memset(dist, 0, sizeof(dist));
		int A, B;
		cin >>A>>B;

		queue<int> q;
		q.push(A);
		visited[A] = 1;
		while(!q.empty()){
			int a = q.front();
			q.pop();

			for(int s : prime){
				if(!visited[s] && can_convert(a, s)){
					visited[s] = 1;
					dist[s] = dist[a] + 1;
					q.push(s);
				}
			}
			if(visited[B]) break;
		}

		if(visited[B]) cout << dist[B];
		else cout << "Impossible";
		ENT
	}


	return 0;
}