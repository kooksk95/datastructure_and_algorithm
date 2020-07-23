#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int T, test_case, n, ans;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin>>n;
        ans = n+1;

        for(int p=2; p*p<=n; p++){
            if(n%p == 0){
                if(n/p < p-1){
                    ans = min(ans, p-1);
                }
            }
        }

        for(int p=2; p*p+p+1<=n; p++){
        	bool valid = 1;
        	int x = n%p;
        	int m = n;
        	while(m){
        		if(m%p != x) {valid=0; break;}
        		m/=p;
        	}
        	if(valid) ans=min(ans, p);
        }

		cout << "Case #" << test_case+1 << endl;
		cout << ans << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}