/*
	하나로 - N개의 섬의 MST 길이 구하기
*/
#include <bits/stdc++.h>
using namespace std;
#define MX 1000
#define INF
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define ENT cout<<"\n";
#define REP(i,a,b) for(auto i=a; i<b; i++)
typedef pair<int,int> pi;
typedef vector<int> vi;

pi islands[MX];
double e;
int n, parent[MX];

int find_set(int a){
	if(parent[a]<0) return a;
	return parent[a] = find_set(parent[a]);
}

void union_set(int a, int b){
	parent[find_set(b)] = find_set(a);
}

double get_dist(int a, int b){
	int x1=islands[a].first, y1=islands[a].second;
	int x2=islands[b].first, y2=islands[b].second;

	return pow(x1-x2,2) + pow(y1-y2,2);
}

int main(int argc, char** argv){

	int test_case;
	int T;
	cin>>T;
	cout.setf(ios::fixed);
	for(test_case = 1; test_case <= T; ++test_case)
	{
		memset(parent, -1, sizeof(parent));
		cin>>n;
		REP(i,0,n) cin>>islands[i].first;
		REP(i,0,n) cin>>islands[i].second;
		
		vector<pair<double, pi>> edges;
		REP(i,0,n-1){
			REP(j,i+1,n){
				pi sd = {i, j};
				double dist = get_dist(i,j);
				edges.push_back({dist, sd});
			}
		}

		sort(edges.begin(), edges.end());
		double s=edges.size(), cnt=0, mst=0;

		REP(i,0,s){
			double dist = edges[i].first;
			int island1 = edges[i].second.first;
			int island2 = edges[i].second.second;
			if(find_set(island1) == find_set(island2)) 
				continue;

			union_set(island1, island2);
			mst += dist;
			cnt++;
			if(cnt==n-1)break;
		}

		cin>>e;
		long long ans = round(mst*e);

		cout<<"#"<<test_case<<" "<<ans;
		ENT

	}

	return 0;
}