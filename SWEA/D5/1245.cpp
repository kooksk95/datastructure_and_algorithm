/*
	균형점 - 물체 사이에 인력이 작용할 때, 균형을 이루는 좌표를 찾으시오
*/
#include<bits/stdc++.h>
using namespace std;
#define ENT cout<<"\n";
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define INF
#define ERR 0.000000000001
#define REP(i,a,b) for(auto i=a; i<b; i++)
typedef vector<int> vi;
typedef pair<int,int> pi;

int n, position[10], weight[10];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	cout.setf(ios::fixed);
	cout.precision(10);
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>n;
		REP(i,0,n)
			cin >> position[i];
		REP(i,0,n)
			cin >> weight[i];
		

		cout << "#" << test_case << " "; 		
		REP(i,0,n-1){
			double left = position[i], right = position[i+1], ans = 0;
			REP(k,0,100){
				double mid = (left+right)/2;
				double val = 0;
				REP(j,0,n){
					double calc = weight[j] / pow(mid-position[j], 2);
					if(position[j] < mid)
						val += calc;
					else
						val -= calc;
				}
				if(val>0) left = mid;
				else
					ans = right = mid;
			}
			cout << " " << ans;
		}
		ENT
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}