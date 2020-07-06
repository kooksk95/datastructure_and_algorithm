/*

    Ladder1 - 도착점 X에 대응되는 출발점 반환

*/

#include<bits/stdc++.h>

using namespace std;

int arr[102][102];

int move_side(int r, int c, int direction){
    int add = direction ? 1 : -1;
    
    while(1) {
        c += add;
        if(arr[r+1][c]) break;
    }
    
    return c;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

    for(test_case = 1; test_case <= T; ++test_case)
	{
        memset(arr, 0, sizeof(arr));
		int val, dest;
        cin >> val;

		for(int i =1; i <= 100; i++){
            for (int j = 1; j<=100; j++) {
                cin >> arr[i][j];
                if (i == 100 && arr[i][j] == 2)
                    dest = j;
            }
        }
        
        int r = 100, c = dest;
        while(r) {
            if (arr[r][c-1] == 1)
                c = move_side(r, c, 0);
            else if (arr[r][c+1] == 1)
                c = move_side(r, c, 1);
            
            r--;
        }
        
		cout << "#" << test_case << " " << c-1 << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}