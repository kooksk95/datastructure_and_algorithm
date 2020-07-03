#include <bits/stdc++.h>
using namespace std;
    
int region[101][101], visited[101][101];
int n, safe_zone, water;
int xy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

bool in_range(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

int dfs(int x, int y){
    if(region[x][y] <= water) visited[x][y] = 1;

    if(!visited[x][y]){
        visited[x][y] = 1;
        for(int i = 0; i<4; i++){
            int next_x = x+xy[i][0];
            int next_y = y+xy[i][1];

            if(in_range(next_x, next_y))
                dfs(next_x, next_y);
        }
        return 1;
    }
    return 0;
}

int flood(){
    memset(visited, 0, sizeof(visited));
    safe_zone = 0;

    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            safe_zone += dfs(i, j);

    return safe_zone;
}

int main(){
    cin >> n;
    int max_height = 0, min_height = 100;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> region[i][j];
            max_height = max(max_height, region[i][j]);
            min_height = min(min_height, region[i][j]);
        }
    }


    int answer = 1;
    for(int f = min_height; f < max_height; f++){
        water = f;
        answer = max(answer, flood());
    }

    cout << answer;
    return 0;
}
