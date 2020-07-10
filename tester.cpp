#include<bits/stdc++.h>
using namespace std;
#define ENT cout<<"\n";
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define MX 10001
#define REP(i,a,b) for(auto i=a; i<b; i++)
typedef vector<int> vi;
typedef pair<int,int> pi;

int v, e, t1, t2, parent[MX], child[MX][3];

int subtree(int n){
	if(child[n][0] == 0) return 1; // leaf node

	int ret = subtree(child[n][1]);
	if(child[n][0] == 2) ret += subtree(child[n][2]);
	return ret+1;
}

stack<int> find_anc(int n){
	stack<int> ret;
	while(parent[n]>0){
		ret.push(parent[n]);
		n = parent[n];
	}

	return ret;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	parent[1] = 0;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		memset(child, 0, sizeof(child));
		cin >>v>>e>>t1>>t2;

		while(e--){
			int p, c;
			cin>>p>>c;
			parent[c] = p;
			child[p][++child[p][0]] = c;
		}

		int ancestor = 0;
		stack<int> anc1 = find_anc(t1);
		stack<int> anc2 = find_anc(t2);

		while(!anc1.empty()){
			if(anc1.top() != anc2.top())
				break;
			
			ancestor = anc1.top();
			anc1.pop();
			anc2.pop();
		}
		

		cout <<"#"<<test_case<<" "<<ancestor<<" "<<subtree(ancestor);
		ENT
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}