/*

    Ladder2 - 경로가 가장 짧은 시작점 반환 (중복시 최댓값)

*/

#include<bits/stdc++.h>

using namespace std;
#define ROW 100
#define COL 100
int arr[102][102];
int moved = 0;

int move_side(int r, int c, int direct) {
    int add = direct ? 1 : -1;
    do {
        c += add;
        moved++;
    } while (arr[r+1][c] == 0);

    return c;
}

void get_dist(int c){
    int r = 1;
    moved = 1;
    while(r < ROW) {
        if (arr[r][c-1] == 1) {
            c = move_side(r, c, 0);
        } else if (arr[r][c+1] == 1) {
            c = move_side(r, c,1);
        }
        r++, moved++;
    }
}

int main(int argc, char** argv)
{
	int test_case, T = 10;
	
    for(test_case = 1; test_case <= T; ++test_case)
	{
		memset(arr, 0, sizeof(arr));
		int val; cin >> val;
        
        vector<int> start;
        for(int j = 1; j <= COL; j++) {
        	cin >> arr[1][j];
            if(arr[1][j] == 1)
                start.push_back(j);
        }
        
        for(int i = 2; i <= ROW; i++)
            for(int j = 1; j <= COL; j++)
                cin >> arr[i][j];
                
        int compare = 10000, ans;
        for(int i = 0; i < start.size(); i++){
            get_dist(start[i]);
            
            if(compare >= moved){
                ans = start[i];
                compare = moved;
            }
        }
		
        cout << "#" << test_case << " " << ans-1 << "\n";
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}