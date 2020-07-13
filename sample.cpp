#include<bits/stdc++.h>
using namespace std;
#define ENT cout<<"\n";
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define MX 10001
#define REP(i,a,b) for(auto i=a; i<b; i++)
typedef vector<int> vi;
typedef pair<int,int> pi;

int x[] = {4,10,20};
int y[] = {1,6,20};

double get_dist(int i, int j){
	return (pow(x[i]-x[j],2) + pow(y[i]-y[j],2));
}

int main(int argc, char** argv)
{
	int a = 100;
	char* buf = itoa(a);
	cout<<buf;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}