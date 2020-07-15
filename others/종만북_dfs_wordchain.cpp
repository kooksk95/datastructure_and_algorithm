/*
	단어 목록이 주어질 때, 이를 전부 사용하고 게임이 끝난다면 순서를, 불가능하면 IMPOSSIBLE을 출력하시오
*/
#include <bits/stdc++.h>
using namespace std;
#define MX 26

int n, adj[MX][MX], in[MX], out[MX];
vector<string> edges[MX][MX];
vector<int> path;

void euler(int v){
	for(int j=0; j<MX; j++){
		while (adj[v][j] > 0){
			adj[v][j]--;
			euler(j);
		}
	}

	path.push_back(v);
}

int check_circle(){
	int start = 0, end = 0;
	for(int i=0; i<MX; i++){
		int x = in[i]-out[i];
		if(x == -1) start++;
		else if(x == 1) end++;
		else if(x != 0) return 0;
	}

	if(start==1 && end==1) return 1;
	if(start==0 && end==0) return 2;
	return 0;
}

int main(){
	int T;
	cin>>T;
	for(int t=0; t<T; t++) {
		memset(adj,0,sizeof(adj));
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		path.clear();
		for(int i=0; i<MX; i++)
			for(int j=0; j<MX; j++)
				edges[i][j].clear();

		cin>>n;
		string word;
		int a, b;
		for(int i=0; i<n; i++){
			cin>>word;
			a = word.front()-'a', b=word.back()-'a';
			adj[a][b]++, out[a]++, in[b]++;
			edges[a][b].push_back(word);
		}


		int status = check_circle();
		if(status == 1){
			for(int i=0; i<MX; i++)
				if(in[i] == out[i]-1){
					euler(i);
					break;
				}
		} else if(status == 2) {
			for(int i=0; i<MX; i++)
				if(out[i]){
					euler(i);
					break;
				}
		}

		if(status==0 || path.size()!=n+1)
			cout<<"IMPOSSIBLE\n";
		else {
			reverse(path.begin(), path.end());
			vector<string> answer;
			for(int i=0; i<n; i++){
				a = path[i], b = path[i+1];
				answer.push_back(edges[a][b].back());
				edges[a][b].pop_back();
			}

			for(string x : answer) cout<<x<<" ";
			cout<<"\n";
		}

	 } 

 	return 0; 
}