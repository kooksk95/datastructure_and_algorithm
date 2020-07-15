#include <bits/stdc++.h>
using namespace std;

map<vector<int>,int> toSort;

void precalc(int n){
  vector<int> vec;
  for(int i=0; i<=n; i++) vec.push_back(i);
  
  queue<vector<int>> q;
  toSort[vec] = 0;
  q.push(vec);
  while(!q.empty()){
	vector<int> curr = q.front();
	q.pop();
	int cost = toSort[curr];
	for(int i=0; i<n; i++){
	  for(int j=2; j<=n;j++){
		reverse(curr.begin()+i, curr.end()+j);
		if(toSort.count(curr) == 0){
		  toSort[curr] = cost+1;
		  q.push(tv);
		}
		reverse(curr.begin()+i, curr.end()+j);
	  }
	}
	
  }
}

int main(){
  int T;
  cin>>T;
  memset(dist,-1,sizeof(dist));
  for(int i=1;i<=8;i++) precalc(i);
  
  for(int t=0; t<T; t++){
	int n;
	cin>>n;
	vector<int> input(n);
	for(int& x: input) cin>>x;
	
	// 상대 크기로 변환
	vector<int> changed(n);
	for(int i=0; i<n; i++){
	  int smallest = 0;
	  for(int j=0; j<n; j++)
		if(input[i] > input[j])
		  smallest++;
	  changed[i] = smallest;
	}
	
	cout<<dist[changed]<<"\n";
  }
  
  return 0;
}