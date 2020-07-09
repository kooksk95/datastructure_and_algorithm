#include <bits/stdc++.h>
using namespace std;
#define MX 10000
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define ENT cout<<"\n";
#define REP(i,a,b) for(auto i=a; i<b; i++)
typedef vector<int> vi;
typedef pair<int,int> pi;

int A, B, from[MX];
char path[MX], DSLR[4] = {'D','S','L','R'};
bool visited[MX];

bool valid(int a){
	return (a>=0 && a<MX);
}

void print_path(int digit){
	if(digit == A) return;
	
	print_path(from[digit]);
	cout << path[digit];
}

int dslr(int calc, int op){
	int tmp;
	switch(op){
		case 0:
			calc = calc*2;
			break;
		case 1:
			calc = (calc-1+MX);
			break;
		case 2:
			tmp = calc / 1000;
			calc = calc*10+tmp;
			break;
		case 3:
			tmp = calc % 10;
			calc = calc/10 + tmp*1000;
			break;
	}

	return calc%MX;
}

int main(){

	IOS
	int T; cin >> T;

	while(T--){
		memset(visited, 0, sizeof(visited));
		memset(from, 0, sizeof(from));
		memset(path, 0, sizeof(path));
		cin >> A >> B;

		queue<int> q;
		q.push(A);
		visited[A] = 1;
		while(!q.empty()){
			int a = q.front();
			q.pop();
			
			REP(i, 0, 4){
				int calc = dslr(a, i);

				if(valid(calc) && !visited[calc]){
					visited[calc] = 1;
					from[calc] = a;
					path[calc] = DSLR[i];
					q.push(calc);
				}
			}

			if(visited[B]) break;
		}

		print_path(B);
		ENT
	}

	return 0;
}