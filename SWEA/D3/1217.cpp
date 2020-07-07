/*
    거듭 제곱
*/

#include<iostream>

using namespace std;

int my_power(int base, int m){
    return m == 0 ? 1 : my_power(base, m-1) * base;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int vv; cin >> vv;

        int n, m; cin >>n>>m;
        int output = my_power(n, m);
		cout << "#"<<test_case<<" "<<output<<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}