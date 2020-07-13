#include <bits/stdc++.h>
using namespace std;
#define MX 20
#define INF 1000001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define ENT cout<<"\n";
#define REP(i,a,b) for(auto i=a; i<b; i++)
typedef pair<int,int> pi;
typedef vector<int> vi;

double s1, s2, n=18;
int pascal[MX][MX], prime[]={2,3,5,7,11,13,17};

void fill_pascal(int a){
	REP(i,0,n+1){
		REP(j,0,i+1){
			pascal[i][j] = j==0 || i==j ? 1
										: pascal[i-1][j-1]+pascal[i-1][j];
		}
	}
}

double solve(double x){
	double y = 1-x;
	double ret = 0;

	REP(i,0,19){
		if(find(prime, prime+7, i) != prime+7) continue;

		ret += pow(x,i)*pow(y,18-i)*pascal[18][i];
	}
	return ret;
}

int main(int argc, char** argv){

	int test_case;
	int T;
	cin>>T;
	cout.setf(ios::fixed);
	cout.precision(6);

	fill_pascal(18);

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>s1>>s2;
		double p1=s1/100, p2=s2/100;

		double master1 = solve(p1);
		double master2 = solve(p2);

		cout<<"#"<<test_case<<" "<<(1-master1*master2);
		ENT		

	}

	return 0;
}