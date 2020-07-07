/*
    회문1 - 8*8 문자판에서 가로+세로 회문 갯수
*/
#include<iostream>

using namespace std;
int len, count;
char arr[8][8];

int palindrome(int r, int c){
    int is_palin = 2;
    for(int i = 0; i<len/2; i++) {
        if(arr[r][c+i] != arr[r][c+len-1-i]) {
            is_palin--;
            break;
        }
    }
    
    swap(r, c);
    for(int i = 0; i<len/2; i++) {
        if(arr[r+i][c] != arr[r+len-1-i][c]) {
            is_palin--;
            break;
        }
    }

    return is_palin;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

    for(test_case = 1; test_case <= T; ++test_case)
	{
        // 초기화
        count  = 0;
        cin>>len;
        for(int i = 0; i<8; i++)
            for(int j =0; j<8; j++)
                cin >> arr[i][j];

        for(int i = 0; i<8; i++)
            for(int j = 0; j<9-len; j++)
                count += palindrome(i, j);


        cout << "#" << test_case << " " << count << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}