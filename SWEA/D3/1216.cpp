/*
    회문2 - 100*100 행렬의 최장 회문 길이
*/
#include<bits/stdc++.h>

using namespace std;
char arr[100][100];
int ans;

bool palindrome(int r, int c, int len, int vertical) {
	bool is_palin = 1;
    if(!vertical){
        for(int j = 0; j<len/2; j++) {
            if(arr[r][c+j] != arr[r][c+len-1-j]){
                is_palin = 0;
                break;
            }
        }
    } else {
        for(int j = 0; j<len/2; j++) {
            if(arr[r+j][c] != arr[r+len-1-j][c]){
                is_palin = 0;
                break;
            }
        }
    }
    
    return is_palin;
}

void update_longest(int r, int s, int vertical){
    if(!vertical){
		for(int j = 0; j<101-s; j++){
            if(palindrome(r, j, s, 0)) {
                ans = s;
                break;
            }
        }
    } else {
		for(int j = 0; j<101-s; j++){
            if(palindrome(j, r, s, 1)) {
                ans = s;
                break;
            }
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int vv; cin >>vv;
        ans = 1;
        for(int i = 0; i<100; i++)
            for(int j = 0; j<100; j++) 
                cin >> arr[i][j];
        
        for(int i = 0; i<100; i++) {
            for(int k = 100; k>ans; k--){ // 문제의 크기
            	update_longest(i, k, 0);
            }
        }

        if(ans < 100){
            for(int i = 0; i<100; i++) {
                for(int k = 100; k>ans; k--){ // 문제의 크기
                    update_longest(i, k, 1);
                }
            }
        }
		cout << "#"<<test_case<<" "<<ans<<"\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}