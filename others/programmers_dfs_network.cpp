/*
    네트워크란 컴퓨터가 연결된 형태를 의미합니다. 예를 들어, 컴퓨터 A와
    컴퓨터 B가 직접적으로 연결되어있고, 컴퓨터 B와 컴퓨터 C가 직접적으로
    연결되어 있을 때 컴퓨터 A와 컴퓨터 C도 간접적으로 연결되어 있습니다.
    컴퓨터의 개수와 연결에 대한 정보가 주어질 때 네트워크의 개수를 구하시오.
*/
#include <string>
#include <vector>

using namespace std;
bool visited[200] = {0};

void dfs(int v, int& n, vector<vector<int>>& comp){
    if(visited[v]) return;
    
    visited[v] = 1;
    for(int i = 0; i<n; i++){
        if(i==v || comp[v][i]==0) continue;
        dfs(i, n, comp);
    }
}

int solution(int n, vector<vector<int>> computers) {
    // memset(visited, 0, sizeof(visited));
    int answer = 0;
    
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            answer++;
            dfs(i,n,computers);
        }
    }
    
    return answer;
}