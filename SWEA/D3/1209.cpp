/*

    Sum - 행렬의 행/열/대각의 합 중 최댓값

*/
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

    for(test_case = 1; test_case <= T; ++test_case)
	{
		int val;
		cin >> val;
        
        int row[100] = {0}, col[100] = {0}, diag[2] = {0};
        
        for(int i = 0; i<100; i++) {
        	for(int j = 0; j<100; j++) {
                int val;
                cin >> val;
                row[i] += val, col[j] += val;
                if(i == j) diag[0] += val;
                if (i + j == 99) diag[1] += val;
            }
        }

        int ans = diag[0] > diag[1] ? diag[0] : diag[1];
        for(int i = 0; i<100; i++) {
            if(row[i] > ans) ans = row[i];
            if(col[i] > ans) ans = col[i];
        }
		
        cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}