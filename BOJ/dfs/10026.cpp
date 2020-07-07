#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define REP(i, a, b) for(auto i = a; i<b; i++)

char arr[MAX][MAX];
bool visited[MAX][MAX];
int n;
int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};

bool valid(int r, int c){
    return (r<n && r>=0 && c<n && c>=0);
}

bool can_dist(char curr, char comp){
    if(curr == 'B') return comp != 'B';
    if(comp == 'B') return curr != 'B';
    return false;
}

void sp_dfs(int r, int c, char rgb){
    if(can_dist(rgb, arr[r][c])
        || visited[r][c]) return;


    visited[r][c] = 1;
    REP(i, 0, 4){
        int tr = r + dr[i];
        int tc = c + dc[i];
        if(valid(tr, tc)){
            sp_dfs(tr, tc, rgb);
        }
    }
}

void dfs(int r, int c, char rgb){
    if(arr[r][c] != rgb
        || visited[r][c]) return;


    visited[r][c] = 1;
    REP(i, 0, 4){
        int tr = r + dr[i];
        int tc = c + dc[i];
        if(valid(tr, tc)){
            dfs(tr, tc, rgb);
        }
    }
}

int main(){

    cin >> n;
    REP(i, 0, n) {
        REP(j, 0, n){
            cin >> arr[i][j];
        }
    }

    memset(visited, 0, sizeof(visited));
    int count1 = 0;
    REP(i, 0, n) {
        REP(j, 0, n){
            if(!visited[i][j]){
                count1++;
                dfs(i,j, arr[i][j]);
            }
        }
    }

    memset(visited, 0, sizeof(visited));
    int count2 = 0;
    REP(i, 0, n) {
        REP(j, 0, n){
            if(!visited[i][j]){
                count2++;
                sp_dfs(i,j, arr[i][j]);
            }
        }
    }
    
    cout << count1 << " " << count2;

    return 0;
}