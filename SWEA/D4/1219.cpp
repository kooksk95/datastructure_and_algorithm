/*
    길찾기 - 정점 0에서 99로 가는 경로가 존재하는가?
*/

#include<bits/stdc++.h>

using namespace std;
int adj[100][3]; // (size, adj1, adj2)
bool visited[100];
void dfs(int v) {
    if(visited[v]) return;
    
    visited[v] = 1;
    int edges = adj[v][0];
    for(int i = 0; i<edges; i++) {
        dfs(adj[v][i+1]);
    }
    
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int vv, edge;
        cin >> vv >> edge;
        memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));
        
        while(edge--){
            int s, d; cin>>s>>d;
            int idx = adj[s][0]+1;
            adj[s][idx] = d;
            adj[s][0]++;
        }
        
        dfs(0);
        cout << "#"<<test_case<<" " << visited[99] <<"\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}