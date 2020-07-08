#include <bits/stdc++.h>
using namespace std;
#define MX 20001
#define REP(i,a,b) for(auto i=a; i<b; i++)
#define ENT cout << "\n";

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, v, e;
	cin >> t;

	while(t--){

		cin >> v >> e;
		vector<int> adj[v+1];
		int colored[v+1] = {0};

		REP(i, 0, e){
			int s, d;
			cin >> s >> d;
			adj[s].push_back(d);
			adj[d].push_back(s);
		}

		bool flag = 0;
		REP(start, 1, v+1){
			if(colored[start]) continue;

			queue<int> q;
			colored[start] = 1;

			q.push(start);
			while(!q.empty()){
				int cur = q.front();
				q.pop();

				for(int x : adj[cur]){
					if(!colored[x]){
						colored[x] = colored[cur]%2 + 1;
						q.push(x);
					} else if (colored[x] == colored[cur]){
						flag = 1;
						break;
					}
				}

				if(flag == 1) break;
			}
			if(flag == 1) break;
		}

		if(flag) cout << "NO\n";
		else cout << "YES\n";
	}


	return 0;
}