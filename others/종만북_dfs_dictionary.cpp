/*
	단어들이 주어질 때, 특정 순서(선후관계)에 의해 정렬되지 않았으면 Invalid, 순서가 성립할 경우 임의의 한가지를 출력하시오
*/
#include <bits/stdc++.h>
using namespace std;

vector<char> topo;
bool cycle, graph[26][26], visited[26];
int n;

void check(){
	for(int i=0; i<26; i++){
		for(int j=i+1; j<26; j++){
			if(graph[topo[j]-'a'][topo[i]-'a'])
				cycle = 1;
		}
	}
}

void dfs(int v){
  visited[v] = 1;
  for(int u=0; u<26; u++){
	if(graph[v][u] && !visited[u])
	  dfs(u);
  }
  topo.push_back('a' + v);
}

int main(){
  int T;
  cin>>T;
  for(int t=0; t<T; t++) {
	
	memset(graph, 0, sizeof(graph));
	memset(visited, 0, sizeof(visited));
	topo.clear();
	cycle = 0;
	
	cin>>n;
	vector<string> words(n);
	for(string& x: words) cin>>x;


	for(int i=0; i<n-1; i++){
	  string str1=words[i], str2=words[i+1];
	  int s = min(str1.size(), str2.size());
	  for(int k=0; k<s; k++){
	  	if(str1[k] != str2[k]){
	  		graph[str1[k]-'a'][str2[k]-'a'] = 1;
	  		break;
	  	}
	  }
	}


	for(int i=0; i<26; i++){
	  if(!visited[i])
		dfs(i);
	}

	reverse(topo.begin(), topo.end());
	check();

	
	if(cycle) cout<<"INVALID HYPOTHESIS\n";
	else {
	  
	  for(char c : topo) cout<<c;
	  cout<<"\n";
	}
	  
  }
  
  return 0; 
}