/*
    미로1 - 16*16에서 도착점에 도달할 수 있는가
*/
#include<bits/stdc++.h>

using namespace std;
#define SIZE 16
int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
int visited[SIZE][SIZE];
pair<int,int> start, goal;

void dfs(int r, int c){
    if(visited[r][c] == 1) return;
    
    visited[r][c] = 1;
    // if(r == goal.first && c == goal.second) return;
    for(int i = 0; i<4; i++) {
        int tr = r +dr[i];
        int tc = c +dc[i];
        dfs(tr, tc);
    }
    
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int vv; cin >> vv;
        //int arr[SIZE][SIZE];
        
        for(int i = 0; i<SIZE; i++){
            for(int j = 0; j<SIZE; j++) {
                char c;
                cin >> c;
                visited[i][j] = c-'0';
                if(visited[i][j] == 2) start = {i, j};
                else if(visited[i][j] == 3) goal = {i, j};
            }
        }
        
       dfs(start.first, start.second);
        
        cout << "#"<<test_case<<" "<< (visited[goal.first][goal.second] == 1) <<"\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}