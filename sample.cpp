#include<bits/stdc++.h>

using namespace std;
#define MX 12
#define INF (1<<30)
#define REP(i,a,b) for(auto i=a; i<b; i++)
#define ENT cout<<"\n";
#define IOS ios::sync_with_stdio(0);cin.tie(0);

int main(int argc, char** argv)
{
	int arr[] = {0,1};
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	reverse(v.begin(), v.end());
	for(int x:v)
		cout<<x<<" ";
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}