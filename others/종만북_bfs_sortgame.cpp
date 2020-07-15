/*
	배열이 주어질 때, 몇번의 구간 뒤집기를 통해 오름차순으로 정렬할 수 있는지 반환하시오
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> dist;

string flip(string s, int a, int b){
	for(int i=a; i<=b; i++){
		if(i <= (a+b)/2)
			swap(s[i], s[a+b-i]);
	}
	return s;
}

void precalc(int n){
  string str;
  for(int i=0; i<n; i++) str += to_string(i);
  
  queue<string> q;
  dist[str] = 0;
  q.push(str);
  while(!q.empty()){
	string curr = q.front();
	q.pop();
	for(int i=0; i<n-1; i++){
	  for(int j=i+1; j<n;j++){
		string tv = flip(curr, i, j);
		if(dist.count(tv) == 0){
		  dist[tv] = dist[curr]+1;
		  q.push(tv);
		}
	  }
	}
	
  }
}

int main(){
  int T;
  cin>>T;

  for(int i=1;i<=8;i++) precalc(i);
  
  for(int t=0; t<T; t++){
	int n;
	cin>>n;
	vector<int> input(n);
	for(int& x: input) cin>>x;
	
	// 상대 크기로 변환
	string changed;
	for(int i=0; i<n; i++){
	  int smallest = 0;
	  for(int j=0; j<n; j++)
		if(input[i] > input[j])
		  smallest++;
	  changed += to_string(smallest);
	}
	
	cout<<dist[changed]<<"\n";
  }
  
  return 0;
}