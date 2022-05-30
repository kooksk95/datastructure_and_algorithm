/******************************************

	백준 14594 ~ 1449번 정리되었음

	-> 앞으로 백준 + SNUPS 중스/인트로 정리

*******************************************/


#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define ENT cout<<"\n";
#define INF 1061109567
#define REP(i,a,b) for(auto i=a; i<b; i++)
#define x first
#define y second
#define all(v) v.begin(),v.end()

using namespace std;
using vi=vector<int>;
using vpii=vector<pair<int,int>>;
using pi=pair<int,int>;

int n, m, arr2[100][100], arr1[100];

void print_arr(){
    REP(i,0,n){
        REP(j,0,m){
            cout<<arr2[i][j]<<" ";
        }
        ENT
    }
    ENT
}

/******************* Graph *******************/
bool relax_edge(){
	bool ret = 0;
	REP(i,0,m){
		int u=a[i].u, v=a[i].v, w=a[i].w;
		if(dist[v]>dist[u]+w)
			dist[v] = dist[u]+w;
	}
	return ret;
}

bool valid(int r, int c){
	return r>=0 && r<n && c>=0 && c<m;
}

/******************* Union-Find *******************/
int fi(int x){
	return arr[x] == -1 ? x : arr[x] = fi(arr[x]);
}

void uni(int a, int b){
	a = fi(a);
	b = fi(b);

	arr[b] = a;
}


int main(){
	n=15;

/******************* Graph *******************/
	// input
	int v, e, x, y, w, start, dist[n];
	bool visited[n]; 
	vector<pi> adj[v+1], adj_t[v+1];


	cin>>v>>e;
	memset(dist, 0x3f, sizeof(dist));
	memset(visited, 0, sizeof(visited));

	while(e--) {
		cin>>x>>y>>w;
		adj[x].push_back({w, y});
	}

	// 2d/conditional bfs/dfs

	//// 최단거리
	//1. 다익스트라 (음수 간선 X) - O(n + mlogm)
	priority_queue<pi> pq;
	pq.push({0,start});
	dist[start] = 0;
	while(!pq.empty()){
		x=pq.top().y;
		pq.pop();
		if(visited[x]) continue;

		visited[x] = 1;
		for(auto p : adj[x]){
			if(dist[p.y] > dist[x]+p.x){
				dist[p.y] = dist[x]+p.x;
				pq.push({-dist[p.y], p.y});
			}
		}
	}

	//2. 벨만 포드 (음의 사이클 X) - O(nm)
	int t=n-1;
	while(t--) relax_edge();
	if(relax_edge()) cout<<"음의 사이클";

	//3. 플로이드 워샬 - O(n^3)
	memset(dist, 0x3f, sizeof(dist));
	REP(i,0,n) dist[i][i] = 0;

	while(m--) {
		int u, v, w;
		cin>>u>>v>>w;
		dist[u][v] = w;
	}
	REP(k,0,n){
		REP(i,0,n){
			REP(j,0,n){
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}

	//MST - 크루스칼
	// https://docs.google.com/presentation/d/1BHOeX5s28-QE-3gdSTYa079R4fECNks1FamcVu8RdwU/edit#slide=id.g56a7d632bb_0_49

	//MST - 프림

	//위상정렬


/******************* 이분탐색 *******************/
	int l=1, r=n, ans=n, mid, val, s;
	while(1){
		mid = (l+r)/2;
		val = 0;
		REP(i,0,n-mid+1)
			val= max(arr1[i+mid] - arr1[i], val);
		
		if(l > r) break;
		else if(val >= s) {
			ans = mid;
			r = mid-1;
		} else l = mid+1;

	}

	// or
	int a=0, b=n-1;
	while(a<=b){
		int k=(a+b)/2;
		if(arr1[k] == 11) cout<<"found x";
		if(arr1[k] < 11) a = k+1;
		else b=k-1; 
	}

/******************* 기타 *******************/
	// 구간 쿼리 
	// https://docs.google.com/presentation/d/1fgfnrJQOgLbAWjNjdJ3LaRMAVDb5Bl9DY_PLG6zDgaU/edit#slide=id.g516f6b5508_0_66
	
	// prime - Erathos
	bool not_prime[n] = {0};
	set<int> primes;
	REP(i,2,n){
		if(not_prime[i]) continue;

		primes.insert(i);
		for(int j=2*i; j<n; j+=i) not_prime[j] = 1;
	}

	// undefined line of input
	string str;
	while(getline(cin,str)){
		if(str[0] == '-') break;

		cout<<str<<"\n";
	}

	// GCD & LCM


	// 이항계수 구하기


	// 파일 쓰기
	string str;
	ofstream myfile;
  	myfile.open ("example.txt");
	while(getline(cin,str)){
		myfile<<str<<" ";
	}
  	myfile.close();

	return 0;
}