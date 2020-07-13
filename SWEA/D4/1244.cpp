#include <bits/stdc++.h>
using namespace std;
#define MX 11
#define INF 1000001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define ENT cout<<"\n";
#define REP(i,a,b) for(auto i=a; i<b; i++)
typedef pair<int,int> pi;
typedef vector<int> vi;

int prize, k, memo[1000000][MX], s;

int swap_number(int number, int i, int j){
	string buf = to_string(number);
	int dif = s-buf.size();
	while(dif--)
		buf = '0'+buf;

	swap(buf[i], buf[j]);
	return stoi(buf);
}

int solve(int number, int cnt){
	int& ret = memo[number][cnt];
	if(ret != -1) return ret;

	if(cnt == k) return ret = number;

	ret = 0;
	REP(i,0,s-1){
		REP(j,i+1,s){
			int tmp = solve(swap_number(number, i, j), cnt+1);
			ret = max(ret, tmp);
		}
	}

	return ret;

}

int main(int argc, char** argv){

	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		memset(memo, -1, sizeof(memo));
		cin>>prize>>k;
		string tmp = to_string(prize);
		s = tmp.size();

		cout<<"#"<<test_case<<" "<<solve(prize, 0);
		ENT		

	}

	return 0;
}