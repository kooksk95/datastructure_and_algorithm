#include<bits/stdc++.h>
using namespace std;
#define ENT cout<<"\n";
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define MX 10001
#define REP(i,a,b) for(auto i=a; i<b; i++)
typedef vector<int> vi;
typedef pair<int,int> pi;


int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());

    int h = citations[0]+1, cnt = 1;
    while(h--){
    	// cout<<"# of citation over "<<h<<" = "<<cnt;ENT
    	
    	while(citations[cnt]>=h)
    		cnt++;
    	if(h<=cnt) break;
    }

    return h;
}

int main(int argc, char** argv)
{
	int arr[] = {0,0,0,0};
	vi vec;
	vec.insert(vec.begin(), arr, arr+4);


	cout<<solution(vec);

	return 0;
}

// [10, 9, 4, 1, 1] -> 3
// [0, 1, 3, 5, 5, 5, 5, 5, 5, 6] -> 5
// 0, 1, 1, 1, 1, 3, 3, 4 -> 3
// 5, 5, 5, 0 -> 3
// 9, 9, 8, 7 -> 4
// 5, 5, 5, 5 -> 4
// 5, 5, 5, 5, 5 -> 5
// 2, 2, 2, 2, 2 -> 2
// 0, 0, 0, 0 -> 0