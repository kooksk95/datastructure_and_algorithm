#include<bits/stdc++.h>
using namespace std;
#define ENT cout<<"\n";
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define MX 1000
#define INF 1000000000000
#define REP(i,a,b) for(auto i=a; i<b; i++)
typedef vector<int> vi;
typedef pair<int,int> pi;

int n, x[MX], y[MX];
double dist[MX][MX], e;
bool visited[MX];

double get_dist(int i, int j){
	return (pow(x[i]-x[j],2) + pow(y[i]-y[j],2));
}

double prime(int p, int stage){
	if(stage == n) return 0;

	visited[p] = 1;

	// find nearest island
	int v=p;
	double d=INF;
	REP(i,0,n){
		if(!visited[i] && dist[p][i] < d){
			d = dist[p][i];
			v = i;
		}
	}

	cout<<p<<"->"<<v<<": "<<(long long)dist[p][v];ENT
	visited[v] = 1;
	return d+prime(v, stage+1);

}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	cout.setf(ios::fixed);
	for(test_case = 1; test_case <= T; ++test_case)
	{
		memset(visited, 0, sizeof(visited));
		cin>>n;
		REP(i,0,n) cin>>x[i];
		REP(i,0,n) cin>>y[i];

		REP(i,0,n){
			REP(j,0,n){
				if(i==j) dist[i][j] = 0;
				else if(i>j) dist[i][j] = dist[j][i];
				else dist[i][j] = get_dist(i,j);
			}
		}
		

		cout <<"#"<<test_case<<" "<<(long long) round(e*prime(0,1));
		ENT

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}