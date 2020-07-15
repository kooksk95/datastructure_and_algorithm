#include <string>
#include <vector>

using namespace std;
vector<vector<string>> edges;
int visited[1000000];
string ans_string = "a";

void dfs(string cur, string path, int depth) {
    if (depth == 0) {
        ans_string = min(path, ans_string);
        return;
    }

    for (int i = 0; i < edges.size(); i++) {
        if (cur == edges[i][0] && !visited[i]) {
            visited[i] = 1;
            dfs(edges[i][1], path + edges[i][1], depth-1);
            visited[i] = 0; 
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    edges = tickets;
    dfs("ICN", "ICN", tickets.size());

    vector<string> answer;
    for (int i = 0; i < ans_string.size(); i+=3)
        answer.push_back(ans_string.substr(i, 3));
    
    return answer;
}